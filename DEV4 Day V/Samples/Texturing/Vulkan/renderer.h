// minimalistic code to draw a single triangle, this is not part of the API.
#include "shaderc/shaderc.h" // needed for compiling shaders at runtime
#ifdef _WIN32 // must use MT platform DLL libraries on windows
	#pragma comment(lib, "shaderc_combined.lib")
#endif
// include ktx texture loader, cmake will link the correct platform libs
#define KHRONOS_STATIC // must be defined if ktx libraries are built statically
#include <ktxvulkan.h>
// Simple Vertex Shader
const char* vertexShaderSource = R"(
[[vk::binding(0, 0)]]
cbuffer M4X4 {
	matrix transform;
};
struct VOUT { 
	float4 posH : SV_POSITION;
	float2 uv : UV; 
};
VOUT main(float4 posAndUV : POSITION) {
	float4 pos = float4(posAndUV.xy, 0, 1);
	pos = mul(transform, pos);
	float2 tex = posAndUV.zw;
	VOUT vout = { pos, tex }; 
	return vout;
}
)";
// Simple Pixel Shader
const char* pixelShaderSource = R"(
// You need a Texture2D and a Sampler HLSL object
[[vk::binding(0, 1)]]
Texture2D diffuseMap;
[[vk::binding(0, 1)]]
SamplerState qualityFilter;

// NOTE: It is HIGHLY suggested you always supply a resource's *register/binding* location
// this avoids compiler ambiguity and allows ordering of resource types to be clear
// notice we use space/descriptor 1 for the texture, this is because the uniform buffer uses 0
// unlike Direct3D11 slots are not namespaced per-shader and are globally shared in Vulkan

float4 main(float2 uv : UV) : SV_TARGET 
{	
	float4 texel = diffuseMap.Sample(qualityFilter, uv);
	return texel; // combine with lighting and other textures, etc..
}
)";
// Creation, Rendering & Cleanup
class Renderer
{
	// proxy handles
	GW::SYSTEM::GWindow win;
	GW::GRAPHICS::GVulkanSurface vlk;
	GW::CORE::GEventReceiver shutdown;
	// what we need at a minimum to draw a triangle
	VkDevice device = nullptr;
	VkBuffer vertexHandle = nullptr;
	VkDeviceMemory vertexData = nullptr;
	VkShaderModule vertexShader = nullptr;
	VkShaderModule pixelShader = nullptr;
	// a uniform buffer to rotate our quad. (mainly so you can see how to mix in a buffer)
	std::vector<VkBuffer> matrixBuffer;
	std::vector<VkDeviceMemory> matrixData;
	std::vector <VkDescriptorSet> matrixDescriptorSet;
	// descriptorset layout for vertex shader so we don't need to bind the texture
	VkDescriptorSetLayout vertexDescriptorLayout = nullptr;
	
	/***************** KTX+VULKAN TEXTURING VARIABLES ******************/

	// what we need at minimum to load/apply one texture
	ktxVulkanTexture texture; // one per texture
	VkImageView textureView = nullptr; // one per texture
	VkSampler textureSampler = nullptr; // can be shared, effects quality & addressing mode
	// note that unlike uniform buffers, we don't need one for each "in-flight" frame
	VkDescriptorSet textureDescriptorSet = nullptr; // std::vector<> not required

	// be aware that all pipeline shaders share the same bind points
	VkDescriptorSetLayout pixelDescriptorLayout = nullptr;
	// textures can optionally share descriptor sets/pools/layouts with uniform & storage buffers	
	VkDescriptorPool descriptorPool = nullptr;
	// pipeline settings for drawing (also required)
	VkPipeline pipeline = nullptr;
	VkPipelineLayout pipelineLayout = nullptr;
public:
	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GVulkanSurface _vlk)
	{
		win = _win;
		vlk = _vlk;
		unsigned int width, height;
		win.GetClientWidth(width);
		win.GetClientHeight(height);
		/***************** GEOMETRY INTIALIZATION ******************/
		// Grab the device & physical device so we can allocate some stuff
		VkPhysicalDevice physicalDevice = nullptr;
		vlk.GetDevice((void**)&device);
		vlk.GetPhysicalDevice((void**)&physicalDevice);

		// Create Vertex Buffer xy position then uv, vertex struct would be preferred here
		float verts[] = {
			-0.5,   0.5f, 0, 0,
			 0.5f,  0.5f, 1, 0,
			-0.5f, -0.5f, 0, 1, 
			 0.5f, -0.5f, 1, 1,
		};
		// Transfer triangle data to the vertex buffer. (staging would be prefered here)
		GvkHelper::create_buffer(physicalDevice, device, sizeof(verts),
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | 
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &vertexHandle, &vertexData);
		GvkHelper::write_to_buffer(device, vertexData, verts, sizeof(verts));
		
		// create a uniform buffer(one per-frame) to hold a matrix
		unsigned int frameBufferCount = 0;
		vlk.GetSwapchainImageCount(frameBufferCount);
		matrixBuffer.resize(frameBufferCount);
		matrixData.resize(frameBufferCount);
		for (int i = 0; i < frameBufferCount; ++i) {
			GvkHelper::create_buffer(physicalDevice, device, sizeof(GW::MATH::GMATRIXF),
				VK_BUFFER_USAGE_UNIFORM_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &matrixBuffer[i], &matrixData[i]);
			GvkHelper::write_to_buffer(device, matrixData[i], 
				&GW::MATH::GIdentityMatrixF, sizeof(GW::MATH::GMATRIXF));
		}

		/***************** SHADER INTIALIZATION ******************/
		// Intialize runtime shader compiler HLSL -> SPIRV
		shaderc_compiler_t compiler = shaderc_compiler_initialize();
		shaderc_compile_options_t options = shaderc_compile_options_initialize();
		shaderc_compile_options_set_source_language(options, shaderc_source_language_hlsl);
		shaderc_compile_options_set_invert_y(options, true);
#ifndef NDEBUG
		shaderc_compile_options_set_generate_debug_info(options);
#endif
		// Create Vertex Shader
		shaderc_compilation_result_t result = shaderc_compile_into_spv( // compile
			compiler, vertexShaderSource, strlen(vertexShaderSource),
			shaderc_vertex_shader, "main.vert", "main", options);
		if (shaderc_result_get_compilation_status(result) != shaderc_compilation_status_success) // errors?
			std::cout << "Vertex Shader Errors: " << shaderc_result_get_error_message(result) << std::endl;
		GvkHelper::create_shader_module(device, shaderc_result_get_length(result), // load into Vulkan
			(char*)shaderc_result_get_bytes(result), &vertexShader);
		shaderc_result_release(result); // done
		// Create Pixel Shader
		result = shaderc_compile_into_spv( // compile
			compiler, pixelShaderSource, strlen(pixelShaderSource),
			shaderc_fragment_shader, "main.frag", "main", options);
		if (shaderc_result_get_compilation_status(result) != shaderc_compilation_status_success) // errors?
			std::cout << "Pixel Shader Errors: " << shaderc_result_get_error_message(result) << std::endl;
		GvkHelper::create_shader_module(device, shaderc_result_get_length(result), // load into Vulkan
			(char*)shaderc_result_get_bytes(result), &pixelShader);
		shaderc_result_release(result); // done
		// Free runtime shader compiler resources
		shaderc_compile_options_release(options);
		shaderc_compiler_release(compiler);

		/***************** PIPELINE INTIALIZATION ******************/
		// Create Pipeline & Layout (Thanks Tiny!)
		VkRenderPass renderPass;
		vlk.GetRenderPass((void**)&renderPass);
		VkPipelineShaderStageCreateInfo stage_create_info[2] = {};
		// Create Stage Info for Vertex Shader
		stage_create_info[0].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		stage_create_info[0].stage = VK_SHADER_STAGE_VERTEX_BIT;
		stage_create_info[0].module = vertexShader;
		stage_create_info[0].pName = "main";
		// Create Stage Info for Fragment Shader
		stage_create_info[1].sType = VK_STRUCTURE_TYPE_PIPELINE_SHADER_STAGE_CREATE_INFO;
		stage_create_info[1].stage = VK_SHADER_STAGE_FRAGMENT_BIT;
		stage_create_info[1].module = pixelShader;
		stage_create_info[1].pName = "main";
		// Assembly State
		VkPipelineInputAssemblyStateCreateInfo assembly_create_info = {};
		assembly_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_INPUT_ASSEMBLY_STATE_CREATE_INFO;
		assembly_create_info.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_STRIP;
		assembly_create_info.primitiveRestartEnable = false;
		// Vertex Input State
		VkVertexInputBindingDescription vertex_binding_description = {};
		vertex_binding_description.binding = 0;
		vertex_binding_description.stride = sizeof(float) * 4;
		vertex_binding_description.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
		VkVertexInputAttributeDescription vertex_attribute_description[1] = {
			{ 0, 0, VK_FORMAT_R32G32B32A32_SFLOAT, 0 } //uv, normal, etc....
		};
		VkPipelineVertexInputStateCreateInfo input_vertex_info = {};
		input_vertex_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		input_vertex_info.vertexBindingDescriptionCount = 1;
		input_vertex_info.pVertexBindingDescriptions = &vertex_binding_description;
		input_vertex_info.vertexAttributeDescriptionCount = 1;
		input_vertex_info.pVertexAttributeDescriptions = vertex_attribute_description;
		// Viewport State (we still need to set this up even though we will overwrite the values)
		VkViewport viewport = {
            0, 0, static_cast<float>(width), static_cast<float>(height), 0, 1
        };
        VkRect2D scissor = { {0, 0}, {width, height} };
		VkPipelineViewportStateCreateInfo viewport_create_info = {};
		viewport_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VIEWPORT_STATE_CREATE_INFO;
		viewport_create_info.viewportCount = 1;
		viewport_create_info.pViewports = &viewport;
		viewport_create_info.scissorCount = 1;
		viewport_create_info.pScissors = &scissor;
		// Rasterizer State
		VkPipelineRasterizationStateCreateInfo rasterization_create_info = {};
		rasterization_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_RASTERIZATION_STATE_CREATE_INFO;
		rasterization_create_info.rasterizerDiscardEnable = VK_FALSE;
		rasterization_create_info.polygonMode = VK_POLYGON_MODE_FILL;
		rasterization_create_info.lineWidth = 1.0f;
		rasterization_create_info.cullMode = VK_CULL_MODE_NONE;
		rasterization_create_info.frontFace = VK_FRONT_FACE_CLOCKWISE;
		rasterization_create_info.depthClampEnable = VK_FALSE;
		rasterization_create_info.depthBiasEnable = VK_FALSE;
		rasterization_create_info.depthBiasClamp = 0.0f;
		rasterization_create_info.depthBiasConstantFactor = 0.0f;
		rasterization_create_info.depthBiasSlopeFactor = 0.0f;
		// Multisampling State
		VkPipelineMultisampleStateCreateInfo multisample_create_info = {};
		multisample_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_MULTISAMPLE_STATE_CREATE_INFO;
		multisample_create_info.sampleShadingEnable = VK_FALSE;
		multisample_create_info.rasterizationSamples = VK_SAMPLE_COUNT_1_BIT;
		multisample_create_info.minSampleShading = 1.0f;
		multisample_create_info.pSampleMask = VK_NULL_HANDLE;
		multisample_create_info.alphaToCoverageEnable = VK_FALSE;
		multisample_create_info.alphaToOneEnable = VK_FALSE;
		// Depth-Stencil State
		VkPipelineDepthStencilStateCreateInfo depth_stencil_create_info = {};
		depth_stencil_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DEPTH_STENCIL_STATE_CREATE_INFO;
		depth_stencil_create_info.depthTestEnable = VK_TRUE;
		depth_stencil_create_info.depthWriteEnable = VK_TRUE;
		depth_stencil_create_info.depthCompareOp = VK_COMPARE_OP_LESS;
		depth_stencil_create_info.depthBoundsTestEnable = VK_FALSE;
		depth_stencil_create_info.minDepthBounds = 0.0f;
		depth_stencil_create_info.maxDepthBounds = 1.0f;
		depth_stencil_create_info.stencilTestEnable = VK_FALSE;
		// Color Blending Attachment & State
		VkPipelineColorBlendAttachmentState color_blend_attachment_state = {};
		color_blend_attachment_state.colorWriteMask = 0xF;
		color_blend_attachment_state.blendEnable = VK_FALSE;
		color_blend_attachment_state.srcColorBlendFactor = VK_BLEND_FACTOR_SRC_COLOR;
		color_blend_attachment_state.dstColorBlendFactor = VK_BLEND_FACTOR_DST_COLOR;
		color_blend_attachment_state.colorBlendOp = VK_BLEND_OP_ADD;
		color_blend_attachment_state.srcAlphaBlendFactor = VK_BLEND_FACTOR_SRC_ALPHA;
		color_blend_attachment_state.dstAlphaBlendFactor = VK_BLEND_FACTOR_DST_ALPHA;
		color_blend_attachment_state.alphaBlendOp = VK_BLEND_OP_ADD;
		VkPipelineColorBlendStateCreateInfo color_blend_create_info = {};
		color_blend_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_COLOR_BLEND_STATE_CREATE_INFO;
		color_blend_create_info.logicOpEnable = VK_FALSE;
		color_blend_create_info.logicOp = VK_LOGIC_OP_COPY;
		color_blend_create_info.attachmentCount = 1;
		color_blend_create_info.pAttachments = &color_blend_attachment_state;
		color_blend_create_info.blendConstants[0] = 0.0f;
		color_blend_create_info.blendConstants[1] = 0.0f;
		color_blend_create_info.blendConstants[2] = 0.0f;
		color_blend_create_info.blendConstants[3] = 0.0f;
		// Dynamic State 
		VkDynamicState dynamic_state[2] = { 
			// By setting these we do not need to re-create the pipeline on Resize
			VK_DYNAMIC_STATE_VIEWPORT, VK_DYNAMIC_STATE_SCISSOR
		};
		VkPipelineDynamicStateCreateInfo dynamic_create_info = {};
		dynamic_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_DYNAMIC_STATE_CREATE_INFO;
		dynamic_create_info.dynamicStateCount = 2;
		dynamic_create_info.pDynamicStates = dynamic_state;

		// desribes the order and type of resources bound to the vertex shader
		VkDescriptorSetLayoutBinding vshader_descriptor_layout_binding = {};
		vshader_descriptor_layout_binding.binding = 0;
		vshader_descriptor_layout_binding.descriptorCount = 1;
		vshader_descriptor_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		vshader_descriptor_layout_binding.stageFlags = VK_SHADER_STAGE_VERTEX_BIT;
		vshader_descriptor_layout_binding.pImmutableSamplers = nullptr;
		// create vertex shader layout
		VkDescriptorSetLayoutCreateInfo descriptor_create_info = {};
		descriptor_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;
		descriptor_create_info.flags = 0;
		descriptor_create_info.bindingCount = 1;
		descriptor_create_info.pBindings = &vshader_descriptor_layout_binding;
		descriptor_create_info.pNext = nullptr;
		VkResult r = vkCreateDescriptorSetLayout(device, &descriptor_create_info,
			nullptr, &vertexDescriptorLayout);
		
		/***************** TEXTURE DESCRIPTOR FOR FRAGMENT/PIXEL SHADER ******************/

		// desribes the order and type of resources bound to the pixel shader
		VkDescriptorSetLayoutBinding pshader_descriptor_layout_binding = {};
		pshader_descriptor_layout_binding.binding = 0;
		pshader_descriptor_layout_binding.descriptorCount = 1;
		pshader_descriptor_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		pshader_descriptor_layout_binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT;
		pshader_descriptor_layout_binding.pImmutableSamplers = nullptr;
		// pixel shader will have its own descriptor set layout
		descriptor_create_info.pBindings = &pshader_descriptor_layout_binding;
		r = vkCreateDescriptorSetLayout(device, &descriptor_create_info,
			nullptr, &pixelDescriptorLayout);
		// Create a descriptor pool!
		// this is how many unique descriptor sets you want to allocate 
		// we need one for each uniform buffer and one for each unique texture
		unsigned int total_descriptorsets = matrixBuffer.size() + 1; 
		VkDescriptorPoolCreateInfo descriptorpool_create_info = {};
		descriptorpool_create_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		VkDescriptorPoolSize descriptorpool_size[2] = {
			{ VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER, matrixBuffer.size() },
			{ VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER, 1 }
		};
		descriptorpool_create_info.poolSizeCount = 2;
		descriptorpool_create_info.pPoolSizes = descriptorpool_size;
		descriptorpool_create_info.maxSets = total_descriptorsets;
		descriptorpool_create_info.flags = 0;
		descriptorpool_create_info.pNext = nullptr;
		vkCreateDescriptorPool(device, &descriptorpool_create_info, nullptr, &descriptorPool);
		// Create a descriptor set for our texture!
		VkDescriptorSetAllocateInfo descriptorset_allocate_info = {};
		descriptorset_allocate_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;
		descriptorset_allocate_info.descriptorSetCount = 1;
		descriptorset_allocate_info.pSetLayouts = &pixelDescriptorLayout;
		descriptorset_allocate_info.descriptorPool = descriptorPool;
		descriptorset_allocate_info.pNext = nullptr;
		r = vkAllocateDescriptorSets(device, &descriptorset_allocate_info, &textureDescriptorSet);
		// end texturing descriptor specifics

		// allocate & link descriptorsets for matrix buffers
		descriptorset_allocate_info.pSetLayouts = &vertexDescriptorLayout;
		VkWriteDescriptorSet write_descriptorset = {};
		write_descriptorset.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		write_descriptorset.descriptorCount = 1;
		write_descriptorset.dstArrayElement = 0;
		write_descriptorset.dstBinding = 0;
		write_descriptorset.descriptorType = VK_DESCRIPTOR_TYPE_UNIFORM_BUFFER;
		VkDescriptorBufferInfo dbinfo = { nullptr, 0, VK_WHOLE_SIZE };
		write_descriptorset.pBufferInfo = &dbinfo;
		matrixDescriptorSet.resize(frameBufferCount);
		for (int i = 0; i < frameBufferCount; ++i) {
			r = vkAllocateDescriptorSets(device, &descriptorset_allocate_info, &matrixDescriptorSet[i]);
			write_descriptorset.dstSet = matrixDescriptorSet[i];
			dbinfo.buffer = matrixBuffer[i];
			vkUpdateDescriptorSets(device, 1, &write_descriptorset, 0, nullptr);
		};
		// Descriptor pipeline layout
		VkPipelineLayoutCreateInfo pipeline_layout_create_info = {};
		pipeline_layout_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		// by having multiple layouts, its possible to split descriptorSets by frequency of update
		pipeline_layout_create_info.setLayoutCount = 2;
		VkDescriptorSetLayout layouts[2] = { vertexDescriptorLayout, pixelDescriptorLayout };
		pipeline_layout_create_info.pSetLayouts = layouts;
		pipeline_layout_create_info.pushConstantRangeCount = 0;
		pipeline_layout_create_info.pPushConstantRanges = nullptr;
		vkCreatePipelineLayout(device, &pipeline_layout_create_info, nullptr, &pipelineLayout);
		// Pipeline State... (FINALLY)
		VkGraphicsPipelineCreateInfo pipeline_create_info = {};
		pipeline_create_info.sType = VK_STRUCTURE_TYPE_GRAPHICS_PIPELINE_CREATE_INFO;
		pipeline_create_info.stageCount = 2;
		pipeline_create_info.pStages = stage_create_info;
		pipeline_create_info.pInputAssemblyState = &assembly_create_info;
		pipeline_create_info.pVertexInputState = &input_vertex_info;
		pipeline_create_info.pViewportState = &viewport_create_info;
		pipeline_create_info.pRasterizationState = &rasterization_create_info;
		pipeline_create_info.pMultisampleState = &multisample_create_info;
		pipeline_create_info.pDepthStencilState = &depth_stencil_create_info;
		pipeline_create_info.pColorBlendState = &color_blend_create_info;
		pipeline_create_info.pDynamicState = &dynamic_create_info;
		pipeline_create_info.layout = pipelineLayout;
		pipeline_create_info.renderPass = renderPass;
		pipeline_create_info.subpass = 0;
		pipeline_create_info.basePipelineHandle = VK_NULL_HANDLE;
		vkCreateGraphicsPipelines(device, VK_NULL_HANDLE, 1, 
			&pipeline_create_info, nullptr, &pipeline);

		// With pipeline created, lets load in our texture and bind it to our descriptor set
		LoadTextures("../../Textures/greendragon.ktx");

		/***************** CLEANUP / SHUTDOWN ******************/
		// GVulkanSurface will inform us when to release any allocated resources
		shutdown.Create(vlk, [&]() {
			if (+shutdown.Find(GW::GRAPHICS::GVulkanSurface::Events::RELEASE_RESOURCES, true)) {
				CleanUp(); // unlike D3D we must be careful about destroy timing
			}
		}); 
	}

	/***************** KTX TEXTURE LOADING & VULKAN SAMPLER/IMGVIEW CREATION ******************/

	// ideally this would take multiple/all textures you want to load
	bool LoadTextures(const char* texturePath)
	{
		// Gateware, access to underlying Vulkan queue and command pool & physical device
		VkQueue graphicsQueue;
		VkCommandPool cmdPool;
		VkPhysicalDevice physicalDevice;
		vlk.GetGraphicsQueue((void**)&graphicsQueue);
		vlk.GetCommandPool((void**)&cmdPool);
		vlk.GetPhysicalDevice((void**)&physicalDevice);
		// libktx, temporary variables
		ktxTexture* kTexture;
		KTX_error_code ktxresult;
		ktxVulkanDeviceInfo vdi;
		// used to transfer texture CPU memory to GPU. just need one
		ktxresult = ktxVulkanDeviceInfo_Construct(&vdi, physicalDevice, device,
			graphicsQueue, cmdPool, nullptr);
		if (ktxresult != KTX_error_code::KTX_SUCCESS)
			return false;
		// load texture into CPU memory from file
		ktxresult = ktxTexture_CreateFromNamedFile(texturePath,
			KTX_TEXTURE_CREATE_NO_FLAGS, &kTexture);
		if (ktxresult != KTX_error_code::KTX_SUCCESS)
			return false;
		// This gets mad if you don't encode/save the .ktx file in a format Vulkan likes
		ktxresult = ktxTexture_VkUploadEx(kTexture, &vdi, &texture,
			VK_IMAGE_TILING_OPTIMAL,
			VK_IMAGE_USAGE_SAMPLED_BIT,
			VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL);
		if (ktxresult != KTX_error_code::KTX_SUCCESS)
			return false;
		// after loading all textures you don't need these anymore
		ktxTexture_Destroy(kTexture);
		ktxVulkanDeviceInfo_Destruct(&vdi);
		
		// create the the image view and sampler
		VkSamplerCreateInfo samplerInfo = {};
		// Set the struct values
		samplerInfo.sType = VK_STRUCTURE_TYPE_SAMPLER_CREATE_INFO;
		samplerInfo.flags = 0;
		samplerInfo.addressModeU = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER; // REPEAT IS COMMON
		samplerInfo.addressModeV = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
		samplerInfo.addressModeW = VK_SAMPLER_ADDRESS_MODE_CLAMP_TO_BORDER;
		samplerInfo.magFilter = VK_FILTER_LINEAR;
		samplerInfo.minFilter = VK_FILTER_LINEAR;
		samplerInfo.mipmapMode = VK_SAMPLER_MIPMAP_MODE_LINEAR;
		samplerInfo.mipLodBias = 0;
		samplerInfo.minLod = 0;
		samplerInfo.maxLod = texture.levelCount;
		samplerInfo.anisotropyEnable = VK_FALSE;
		samplerInfo.maxAnisotropy = 1.0;
		samplerInfo.borderColor = VK_BORDER_COLOR_FLOAT_OPAQUE_WHITE;
		samplerInfo.compareEnable = VK_FALSE;
		samplerInfo.compareOp = VK_COMPARE_OP_LESS;
		samplerInfo.unnormalizedCoordinates = VK_FALSE;
		samplerInfo.pNext = nullptr;
		VkResult vr = vkCreateSampler(device, &samplerInfo, nullptr, &textureSampler);
		if (vr != VkResult::VK_SUCCESS) 
			return false;

		// Create image view.
		// Textures are not directly accessed by the shaders and are abstracted
		// by image views containing additional information and sub resource ranges.
		VkImageViewCreateInfo viewInfo = {};
		// Set the non-default values.
		viewInfo.sType = VK_STRUCTURE_TYPE_IMAGE_VIEW_CREATE_INFO;
		viewInfo.flags = 0;
		viewInfo.components = {
			VK_COMPONENT_SWIZZLE_R, VK_COMPONENT_SWIZZLE_G, 
			VK_COMPONENT_SWIZZLE_B, VK_COMPONENT_SWIZZLE_A
		};
		viewInfo.image = texture.image;
		viewInfo.format = texture.imageFormat;
		viewInfo.viewType = texture.viewType;
		viewInfo.subresourceRange.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
		viewInfo.subresourceRange.layerCount = texture.layerCount;
		viewInfo.subresourceRange.levelCount = texture.levelCount;
		viewInfo.subresourceRange.baseMipLevel = 0;
		viewInfo.subresourceRange.baseArrayLayer = 0;
		viewInfo.pNext = nullptr;
		vr = vkCreateImageView(device, &viewInfo, nullptr, &textureView);
		if (vr != VkResult::VK_SUCCESS) 
			return false;

		// update the descriptor set(s) to point to the correct views
		VkWriteDescriptorSet write_descriptorset = {};
		write_descriptorset.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		write_descriptorset.descriptorCount = 1;
		write_descriptorset.dstArrayElement = 0;
		write_descriptorset.dstBinding = 0;
		write_descriptorset.descriptorType = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
		write_descriptorset.dstSet = textureDescriptorSet;
		VkDescriptorImageInfo diinfo = { textureSampler, textureView, texture.imageLayout };
		write_descriptorset.pImageInfo = &diinfo;
		vkUpdateDescriptorSets(device, 1, &write_descriptorset, 0, nullptr);

		return true;
	}
	void Update()
	{
		// grab the current Vulkan commandBuffer and framebuffer index
		unsigned int currentBuffer;
		vlk.GetSwapchainCurrentImage(currentBuffer);
		VkCommandBuffer commandBuffer;
		vlk.GetCommandBuffer(currentBuffer, (void**)&commandBuffer);

		// lets just do a simple time based rotation
		GW::MATH::GMATRIXF spinner;
		static auto start = std::chrono::steady_clock::now();
		double elapsed = std::chrono::duration<double>(
			std::chrono::steady_clock::now() - start).count();
		GW::MATH::GMatrix::RotationYawPitchRollF( 0, 0, cos(elapsed), spinner);
		// copy to active unifom buffer for this frame
		GvkHelper::write_to_buffer(device, matrixData[currentBuffer],
			&spinner, sizeof(GW::MATH::GMATRIXF));
	}
	void Render()
	{
		// grab the current Vulkan commandBuffer
		unsigned int currentBuffer;
		vlk.GetSwapchainCurrentImage(currentBuffer);
		VkCommandBuffer commandBuffer;
		vlk.GetCommandBuffer(currentBuffer, (void**)&commandBuffer);
		// what is the current client area dimensions?
		unsigned int width, height;
		win.GetClientWidth(width);
		win.GetClientHeight(height);
		// setup the pipeline's dynamic settings
		VkViewport viewport = {
            0, 0, static_cast<float>(width), static_cast<float>(height), 0, 1
        };
        VkRect2D scissor = { {0, 0}, {width, height} };
		vkCmdSetViewport(commandBuffer, 0, 1, &viewport);
		vkCmdSetScissor(commandBuffer, 0, 1, &scissor);
		vkCmdBindPipeline(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipeline);
		
		vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
			pipelineLayout, 0, 1, &matrixDescriptorSet[currentBuffer], 0, nullptr);

		/***************** BINDING OF TEXTURE DESCRIPTOR SET TO PIXEL SHADER ******************/

		// *NEW* Set the descriptorSet that contains our texture
		vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS,
			pipelineLayout, 1, 1, &textureDescriptorSet, 0, nullptr);

		// now we can draw
		VkDeviceSize offsets[] = { 0 };
		vkCmdBindVertexBuffers(commandBuffer, 0, 1, &vertexHandle, offsets);
		vkCmdDraw(commandBuffer, 4, 1, 0, 0); // draw a quad
	}
private:
	void CleanUp()
	{
		// wait till everything has completed
		vkDeviceWaitIdle(device);
		// When done using the image in Vulkan...
		ktxVulkanTexture_Destruct(&texture, device, nullptr);
		if (textureView) {
			vkDestroyImageView(device, textureView, nullptr);
			textureView = nullptr;
		}
		if (textureSampler) {
			vkDestroySampler(device, textureSampler, nullptr);
			textureSampler = nullptr;
		}
		// don't need the descriptors anymore
		vkDestroyDescriptorSetLayout(device, vertexDescriptorLayout, nullptr);
		vkDestroyDescriptorSetLayout(device, pixelDescriptorLayout, nullptr);
		vkDestroyDescriptorPool(device, descriptorPool, nullptr);
		// Release allocated buffers, shaders & pipeline
		for (int i = 0; i < matrixBuffer.size(); ++i) {
			vkDestroyBuffer(device, matrixBuffer[i], nullptr);
			vkFreeMemory(device, matrixData[i], nullptr);
		}
		vkDestroyBuffer(device, vertexHandle, nullptr);
		vkFreeMemory(device, vertexData, nullptr);
		vkDestroyShaderModule(device, vertexShader, nullptr);
		vkDestroyShaderModule(device, pixelShader, nullptr);
		vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
		vkDestroyPipeline(device, pipeline, nullptr);
	}
};
