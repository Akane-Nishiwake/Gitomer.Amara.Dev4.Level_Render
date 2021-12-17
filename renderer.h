#include "shaderc/shaderc.h" // needed for compiling shaders at runtime
#ifdef _WIN32 // must use MT platform DLL libraries on windows
#pragma comment(lib, "shaderc_combined.lib") 
#endif
#include "FSLogo.h"
#include "ModelLoader.h"

// Simple Vertex Shader
#pragma region VertexShader
const char* vertexShaderSource = R"(
#pragma pack_matrix(row_major)
[[vk::push_constant]]
cbuffer Mesh_Data
{
    uint mesh_ID;
	uint material_ID;

};
struct OBJ_ATTRIBUTES
{
	float3 Kd;
	float d;
	float3 Ks;
	float Ns;
	float3 Ka;
	float sharpness;
	float3 Tf;
	float Ni;
	float3 Ke;
	uint illum;
};

struct SHADER_MODEL_DATA
{
	float4 sunDirection;
	float4 sunColor; //lighting
	float4 Ambi;
	float4 camWpos;
	matrix view;
	matrix projection; //viewing

	matrix matrices[1024]; //world space
	OBJ_ATTRIBUTES materials[1024]; //texture
};
StructuredBuffer<SHADER_MODEL_DATA> sceneData;
struct Vertex
{
	float3 pos : POSITION;
    float3 uvw : XCOORD;
    float3 nrm : NORMAL;
};

struct OutVertex
{
	float4 pos : SV_POSITION; 
    float2 uv : XCOORD;
    float3 nrm : NORMAL;
    float4 posW : WORLD;
};
OutVertex main(Vertex inputVertex)
{
//changed material_ID to mesh Id and was able to get only one correctly - if any other object are they the other ones do not work
	OutVertex output = (OutVertex)0;
	output.pos = float4(inputVertex.pos, 1);

	output.nrm = mul(float4(inputVertex.nrm, 0), sceneData[mesh_ID].matrices[0]); //normal
	output.posW = mul(float4(inputVertex.pos, 1), sceneData[mesh_ID].matrices[0]); //world
	output.pos = mul(output.pos, sceneData[mesh_ID].matrices[0]); 
	output.pos = mul(output.pos, sceneData[mesh_ID].view);
	output.pos = mul(output.pos, sceneData[mesh_ID].projection); //<-this might be the problem child

	return output;
}
)";

#pragma endregion

#pragma region PixelShader
// Simple Pixel Shader
const char* pixelShaderSource = R"(
[[vk::push_constant]]
cbuffer MeshData
{
    uint mesh_ID;
    uint material_ID;
};
struct OBJ_ATTRIBUTES
{
    float3 Kd;
    float d;
    float3 Ks;
    float Ns;
    float3 Ka;
    float sharpness;
    float3 Tf;
    float Ni;
    float3 Ke;
    uint illum;
};
struct SHADER_MODEL_DATA
{
    float4 sunDirection;
    float4 sunColor; 
	float4 Ambi;
	float4 camWpos;
    matrix view;
    matrix projection;
    matrix matrices[1024]; 
    OBJ_ATTRIBUTES materials[1024]; 
};
struct OutVertex
{
    float4 pos : SV_POSITION;
    float2 uv;
    float3 nrm : NORMAL;
    float4 posW : WORLD;
};

StructuredBuffer<SHADER_MODEL_DATA> sceneData;
float4 main(OutVertex outVert) : SV_TARGET
{
	float4 Am = sceneData[mesh_ID].Ambi;
	float3 viewDirect = normalize(sceneData[mesh_ID].camWpos.xyz - outVert.posW.xyz);
	float3 HalfVec = normalize(-normalize(sceneData[mesh_ID].sunDirection.xyz)  + viewDirect);
	float Intense = saturate(pow( dot(normalize(outVert.nrm),HalfVec), sceneData[mesh_ID].materials[material_ID].Ns));
	float4 Reflection = float4(sceneData[mesh_ID].materials[material_ID].Ks, 0) * Intense * sceneData[mesh_ID].sunColor;
	float ratio = saturate(dot(normalize(-sceneData[mesh_ID].sunDirection.xyz), normalize(outVert.nrm)));
	float4 Lumi = sceneData[mesh_ID].sunColor * ratio;
	float4 materialColor = float4(sceneData[mesh_ID].materials[material_ID].Kd, 0);
	return saturate(Lumi + Am) * materialColor + Reflection;
}
)";
#pragma endregion

// Creation, Rendering & Cleanup
class Renderer
{
#pragma region Initialzers



	// proxy handles
	GW::SYSTEM::GWindow win;
	GW::GRAPHICS::GVulkanSurface vlk;
	GW::CORE::GEventReceiver shutdown;

	// what we need at a minimum to draw a triangle
	VkDevice device = nullptr;
	VkBuffer vertexHandle = nullptr;
	VkDeviceMemory vertexData = nullptr;
	// TODO: Part 1g
	VkBuffer  indexBuffer = nullptr;
	VkDeviceMemory  indexData = nullptr;
	// TODO: Part 2c
	std::vector<VkBuffer> vectorBuffer;
	std::vector<VkDeviceMemory> vectorData;
	VkShaderModule vertexShader = nullptr;
	VkShaderModule pixelShader = nullptr;
	//for camera movement
	GW::INPUT::GInput input;
	GW::INPUT::GController control;
	float deltaTime;
	std::chrono::steady_clock::time_point lastUpdate;
	// pipeline settings for drawing (also required)
	VkPipeline pipeline = nullptr;
	VkPipelineLayout pipelineLayout = nullptr;

	VkDescriptorSetLayout descripLayout = nullptr;

	VkDescriptorPool descripPool = nullptr;

	VkDescriptorSet descripDS = nullptr;

	GW::MATH::GMatrix proxy;
	GW::MATH::GVECTORF eye = { 0, 15, -15, 0 };
	GW::MATH::GVECTORF at = { 0.15f, 0.75f, 0 };
	GW::MATH::GVECTORF up = { 0, 1, 0 };
	GW::MATH::GVECTORF LightDir = { 1.5, -2.5, 2 };
	GW::MATH::GVECTORF LightCol = { 0.9, 0.9, 1, 1 };
	GW::MATH::GVECTORF Ambi = { 0.25,0.25,0.35,1 };
	std::vector<SHADER_MODEL_DATA> shaderData;
	GW::MATH::GMATRIXF view;
	GW::MATH::GMATRIXF projection;
	GW::MATH::GMATRIXF world;
	GW::MATH::GMATRIXF camera;
#pragma endregion
	void fillShaderData(Level& level, VkPhysicalDevice physicalDevice, VkDevice device)
	{
		shaderData.clear();
		float aspect = 0.0f;
		vlk.GetAspectRatio(aspect);
		shaderData.resize(level.myModel.size());
		for (int i = 0; i < level.myModel.size(); i++) // checking all models
		{

			for (int j = 0; j < level.myModel[i].parse.meshCount; j++) //check submeshes
			{
				shaderData[i].matricies[j] = level.myModel[i].modelData.matricies[j]; //setting world matrix
				float debug = 0;
			}
			//view
			proxy.IdentityF(shaderData[i].view);
			proxy.LookAtLHF(eye, at, up, shaderData[i].view);
			//lighting - set model lighting data to the light color and direction
			shaderData[i].sunColor = LightCol;
			shaderData[i].Ambi = Ambi;
			shaderData[i].sunDirection = LightDir;
			shaderData[i].camWpos = eye;
			//projection matrix
			proxy.ProjectionVulkanLHF(G_DEGREE_TO_RADIAN(65), aspect, 0.1f, 150.0f, shaderData[i].projection);
			//materials writing to shader
			for (int k = 0; k < level.myModel[i].parse.materialCount; k++)
			{
				shaderData[i].materials[k] = (OBJ_ATTRIBUTES&)level.myModel[i].parse.materials[k].attrib;
				float debug = 0;
			}
			//buffers
			GvkHelper::create_buffer(physicalDevice, device, sizeof(H2B::VERTEX) * level.myModel[i].parse.vertices.size(),
				VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &level.myModel[i].vertexBuffer, &level.myModel[i].vertexData);
			GvkHelper::write_to_buffer(device, level.myModel[i].vertexData, level.myModel[i].parse.vertices.data(), sizeof(H2B::VERTEX) * level.myModel[i].parse.vertices.size());

			GvkHelper::create_buffer(physicalDevice, device, sizeof(unsigned int) * level.myModel[i].parse.indices.size(),
				VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &level.myModel[i].indexBuffer, &level.myModel[i].indexData);
			GvkHelper::write_to_buffer(device, level.myModel[i].indexData, level.myModel[i].parse.indices.data(), sizeof(unsigned int) * level.myModel[i].parse.indices.size());
		}
	}

public:

	Level newLevel;
	Level switchedLevel;

	Renderer(GW::SYSTEM::GWindow _win, GW::GRAPHICS::GVulkanSurface _vlk)
	{
		win = _win;
		vlk = _vlk;
		//camera movement
		input.Create(win);
		control.Create();
		newLevel.LoadLevel("../GameLevel.txt"); //starting level
		unsigned int image = 0;
		vlk.GetSwapchainImageCount(image);
		vectorBuffer.resize(image);
		vectorData.resize(image);
		unsigned int width, height;
		win.GetClientWidth(width);
		win.GetClientHeight(height);
		VkPhysicalDevice physicalDevice = nullptr;
		vlk.GetDevice((void**)&device);
		vlk.GetPhysicalDevice((void**)&physicalDevice);
		proxy.Create();

		fillShaderData(newLevel, physicalDevice, device);

		/***************** GEOMETRY INTIALIZATION ******************/
		// Grab the device & physical device so we can allocate some stuff

		// Create Vertex Buffer
		float verts[] = {
			   0,   0.5f,
			 0.5f, -0.5f,
			-0.5f, -0.5f
		};
		// Transfer triangle data to the vertex buffer. (staging would be prefered here)
		GvkHelper::create_buffer(physicalDevice, device, sizeof(FSLogo_vertices),
			VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &vertexHandle, &vertexData);
		GvkHelper::write_to_buffer(device, vertexData, FSLogo_vertices, sizeof(FSLogo_vertices));
		// TODO: Part 1g
		GvkHelper::create_buffer(physicalDevice, device, sizeof(FSLogo_indices),
			VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
			VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &indexBuffer, &indexData);
		GvkHelper::write_to_buffer(device, indexData, FSLogo_indices, sizeof(FSLogo_indices));
		// TODO: Part 2d

		for (int i = 0; i < image; i++)
		{
			GvkHelper::create_buffer(physicalDevice, device, sizeof(SHADER_MODEL_DATA) * shaderData.size(),
				VK_BUFFER_USAGE_STORAGE_BUFFER_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT |
				VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, &vectorBuffer[i], &vectorData[i]);
			GvkHelper::write_to_buffer(device, vectorData[i], shaderData.data(), sizeof(SHADER_MODEL_DATA) * shaderData.size());
		}

#pragma region Shader Initialization

		/***************** SHADER INTIALIZATION ******************/
		// Intialize runtime shader compiler HLSL -> SPIRV
		shaderc_compiler_t compiler = shaderc_compiler_initialize();
		shaderc_compile_options_t options = shaderc_compile_options_initialize();
		shaderc_compile_options_set_source_language(options, shaderc_source_language_hlsl);
		shaderc_compile_options_set_invert_y(options, false); // TODO: Part 2i
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
#pragma endregion

#pragma region Pipeline Initialization



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
		assembly_create_info.topology = VK_PRIMITIVE_TOPOLOGY_TRIANGLE_LIST;
		assembly_create_info.primitiveRestartEnable = false;
		// TODO: Part 1e
		// Vertex Input State
		VkVertexInputBindingDescription vertex_binding_description = {};
		vertex_binding_description.binding = 0;
		vertex_binding_description.stride = sizeof(float) * 9;
		vertex_binding_description.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;
		VkVertexInputAttributeDescription vertex_attribute_description[3] = {
			{ 0, 0, VK_FORMAT_R32G32B32_SFLOAT, 0}, //uv, normal, etc....
			{ 1, 0, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 3}, //uv, normal, etc....
			{ 2, 0, VK_FORMAT_R32G32B32_SFLOAT, sizeof(float) * 6 } //uv, normal, etc....
		};
		VkPipelineVertexInputStateCreateInfo input_vertex_info = {};
		input_vertex_info.sType = VK_STRUCTURE_TYPE_PIPELINE_VERTEX_INPUT_STATE_CREATE_INFO;
		input_vertex_info.vertexBindingDescriptionCount = 1;
		input_vertex_info.pVertexBindingDescriptions = &vertex_binding_description;
		input_vertex_info.vertexAttributeDescriptionCount = 3;
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
		rasterization_create_info.cullMode = VK_CULL_MODE_BACK_BIT;
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
		// TODO: Part 2e
		VkDescriptorSetLayoutBinding desc_layout_binding = {};
		desc_layout_binding.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		desc_layout_binding.binding = 0;
		desc_layout_binding.stageFlags = VK_SHADER_STAGE_FRAGMENT_BIT | VK_SHADER_STAGE_VERTEX_BIT;
		desc_layout_binding.descriptorCount = 1;
		desc_layout_binding.pImmutableSamplers = VK_NULL_HANDLE;
		VkDescriptorSetLayoutCreateInfo desc_layout_info = {};
		desc_layout_info.bindingCount = 1;
		desc_layout_info.pBindings = &desc_layout_binding;
		desc_layout_info.pNext = nullptr;
		desc_layout_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_LAYOUT_CREATE_INFO;

		vkCreateDescriptorSetLayout(device, &desc_layout_info, nullptr, &descripLayout);
		VkDescriptorPoolSize desc_pool_size = {};
		desc_pool_size.type = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		desc_pool_size.descriptorCount = 1;
		VkDescriptorPoolCreateInfo desc_pool_info = {};
		desc_pool_info.poolSizeCount = 1;
		desc_pool_info.pNext = nullptr;
		desc_pool_info.pPoolSizes = &desc_pool_size;
		desc_pool_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_POOL_CREATE_INFO;
		desc_pool_info.maxSets = 1;

		vkCreateDescriptorPool(device, &desc_pool_info, nullptr, &descripPool);
		VkDescriptorSetAllocateInfo desc_set_info = {};
		desc_set_info.descriptorPool = descripPool;
		desc_set_info.descriptorSetCount = 1;
		desc_set_info.pSetLayouts = &descripLayout;
		desc_set_info.pNext = nullptr;
		desc_set_info.sType = VK_STRUCTURE_TYPE_DESCRIPTOR_SET_ALLOCATE_INFO;

		vkAllocateDescriptorSets(device, &desc_set_info, &descripDS);

		VkDescriptorBufferInfo desc_buff_info = {};
		desc_buff_info.buffer = vectorBuffer[0];
		desc_buff_info.offset = 0;
		desc_buff_info.range = VK_WHOLE_SIZE;
		VkWriteDescriptorSet write_desc_set = {};
		write_desc_set.descriptorCount = 1;
		write_desc_set.dstArrayElement = 0;
		write_desc_set.pNext = nullptr;
		write_desc_set.sType = VK_STRUCTURE_TYPE_WRITE_DESCRIPTOR_SET;
		write_desc_set.dstBinding = 0;
		write_desc_set.descriptorType = VK_DESCRIPTOR_TYPE_STORAGE_BUFFER;
		write_desc_set.dstSet = descripDS;
		write_desc_set.pBufferInfo = &desc_buff_info;

		vkUpdateDescriptorSets(device, 1, &write_desc_set, 0, nullptr);
		// TODO: Part 4f
		VkPushConstantRange constant_range_info = {};
		constant_range_info.offset = 0;
		constant_range_info.size = sizeof(unsigned int) * 2;
		constant_range_info.stageFlags = VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT;
		// Descriptor pipeline layout
		VkPipelineLayoutCreateInfo pipeline_layout_create_info = {};
		pipeline_layout_create_info.sType = VK_STRUCTURE_TYPE_PIPELINE_LAYOUT_CREATE_INFO;
		// TODO: Part 2e
		pipeline_layout_create_info.setLayoutCount = 1;
		pipeline_layout_create_info.pSetLayouts = &descripLayout;
		// TODO: Part 3c
		pipeline_layout_create_info.pushConstantRangeCount = 1;
		pipeline_layout_create_info.pPushConstantRanges = &constant_range_info;
		vkCreatePipelineLayout(device, &pipeline_layout_create_info,
			nullptr, &pipelineLayout);
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
#pragma endregion
		/***************** CLEANUP / SHUTDOWN ******************/
		// GVulkanSurface will inform us when to release any allocated resources
		shutdown.Create(vlk, [&]() {
			if (+shutdown.Find(GW::GRAPHICS::GVulkanSurface::Events::RELEASE_RESOURCES, true)) {
				CleanUp(); // unlike D3D we must be careful about destroy timing
			}
			});
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

		// now we can draw
		VkDeviceSize offsets[] = { 0 };

		vkCmdBindDescriptorSets(commandBuffer, VK_PIPELINE_BIND_POINT_GRAPHICS, pipelineLayout,
			0, 1, &descripDS, 0, nullptr);
		GvkHelper::write_to_buffer(device, vectorData[currentBuffer], shaderData.data(), sizeof(shaderData[0]) * shaderData.size());
		/* float num1 = 0.0f;
		 input.GetState(G_KEY_1, num1);
		 float num2 = 0.0f;
		 input.GetState(G_KEY_2, num2);
		 if (num1)
		 {
			 newLevel.LoadLevel("../GameLevel.txt");
		 }
		 else if (num2)
		 {
			 switchedLevel.LoadLevel("../GameLevel3.txt");
		 }*/
		 // Level* tempLevel = nullptr;
		 ///* if (num1)
		 // {*/
		 //	 tempLevel = &newLevel;
		 /* }
		  else if (num2)
		  {
			  tempLevel = &switchedLevel;
		  }*/
		  //if key pressed set temp level to & of current level????????????????????????????????????????????????????????????????????????????????????????
	  //MaterialData materialData[2] = {};
		for (int i = 0; i < newLevel.myModel.size(); i++) //for every model
		{
			vkCmdBindVertexBuffers(commandBuffer, 0, 1, &newLevel.myModel[i].vertexBuffer, offsets);
			vkCmdBindIndexBuffer(commandBuffer, newLevel.myModel[i].indexBuffer, 0, VkIndexType::VK_INDEX_TYPE_UINT32);
			for (int j = 0; j < newLevel.myModel[i].parse.meshCount; j++) // for every sub mesh
			{
				unsigned int id[2] = { i, j };
				//materialData[i].material_index = FSLogo_meshes[i].materialIndex;
				vkCmdPushConstants(commandBuffer, pipelineLayout, VK_SHADER_STAGE_VERTEX_BIT | VK_SHADER_STAGE_FRAGMENT_BIT,
					0, sizeof(unsigned int) * 2, id);
				vkCmdDrawIndexed(commandBuffer, newLevel.myModel[i].parse.meshes[j].drawInfo.indexCount, 1, newLevel.myModel[i].parse.meshes[j].drawInfo.indexOffset, 0, 0);
				float debug = 0;
			}
		}


	}
	void CameraUpdate()
	{

		auto now = std::chrono::steady_clock::now();
		deltaTime = std::chrono::duration_cast<std::chrono::microseconds>(now - lastUpdate).count() / 1000000.0f; //seconds
		lastUpdate = now;
		// TODO: Part 4c
		GW::MATH::GMATRIXF inverseView = GW::MATH::GIdentityMatrixF; //copy of view after inverse
		proxy.InverseF(shaderData[0].view, inverseView);
		GW::MATH::GMATRIXF translationMatrix = GW::MATH::GIdentityMatrixF;
		GW::MATH::GMATRIXF pitchMatrix = GW::MATH::GIdentityMatrixF;
		GW::MATH::GMATRIXF yawMatrix = GW::MATH::GIdentityMatrixF;
		// TODO: Part 4d
		const float camSpeed = 5.0f;
		float frameSpeed = camSpeed * deltaTime;
		float thumbSpeed = G_PI_F * deltaTime;
		float FOV = G_DEGREE_TO_RADIAN(65);
		//initializing movment
		float yChange = 0.0f;
		float zChange = 0.0f;
		float xChange = 0.0f;
		float totalPitchY = 0.0f;
		float totalYawX = 0.0f;

		float pitchY = 0.0f;
		float yawX = 0.0f;

		float space = 0.0f;
		float shift = 0.0f;
		float rt = 0.0f;
		float lt = 0.0f;

		float wState = 0.0f;
		float sState = 0.0f;
		float lay = 0.0f;
		float ray = 0.0f;
		float dState = 0.0f;
		float aState = 0.0f;
		float lax = 0.0f;
		float rax = 0.0f;

		//Pitch (up/down) Yaw(side)
		GW::GReturn result = input.GetMouseDelta(yawX, pitchY);
		control.GetState(0, G_RY_AXIS, ray);
		control.GetState(0, G_RX_AXIS, rax);
		//up down
		input.GetState(G_KEY_SPACE, space);
		input.GetState(G_KEY_LEFTSHIFT, shift);
		control.GetState(0, G_RIGHT_TRIGGER_AXIS, rt);
		control.GetState(0, G_LEFT_TRIGGER_AXIS, lt);
		//forward and back
		input.GetState(G_KEY_W, wState);
		input.GetState(G_KEY_S, sState);
		control.GetState(0, G_LY_AXIS, lay);
		//left and right
		input.GetState(G_KEY_D, dState);
		input.GetState(G_KEY_A, aState);
		control.GetState(0, G_LX_AXIS, lax);
		if (space > 0 || shift > 0 || rt > 0 || lt > 0)
		{
			yChange = space - shift + rt - lt;
		}
		inverseView.row4.y += yChange * camSpeed * deltaTime;
		// TODO: Part 4e
		if (wState > 0 || sState > 0 || dState > 0 || aState > 0)
		{
			zChange = sState - wState + lay;
			xChange = aState - dState + lax;
		}
		translationMatrix.row4 = { xChange * frameSpeed, 0, zChange * frameSpeed, 1.0f };

		if (G_PASS(result) && result != GW::GReturn::REDUNDANT)
		{
			// TODO: Part 4f
			if (pitchY != 0)
			{
				totalPitchY = FOV * pitchY / 600 + ray * -thumbSpeed;
			}
			proxy.RotateXLocalF(inverseView, totalPitchY, inverseView); //doesn't stop rotating

			//// TODO: Part 4g
			if (yawX != 0)
			{
				totalYawX = FOV * yawX / 600 + rax * -thumbSpeed;
			}
			GW::MATH::GVECTORF camPos = inverseView.row4;
			inverseView.row4 = { 0, 0, 0, 1 };
			proxy.RotateYGlobalF(inverseView, totalYawX, inverseView);
			inverseView.row4 = camPos;
		}
		// TODO: Part 4c
		//Level* tempLevel = nullptr;

		//add if check for button input
		proxy.InverseF(inverseView, shaderData[0].view);
		proxy.MultiplyMatrixF(shaderData[0].view, translationMatrix, shaderData[0].view);
		for (int i = 0; i < newLevel.myModel.size(); i++)
		{
			shaderData[i].view = shaderData[0].view;
			shaderData[i].camWpos = inverseView.row4;
		}

	}

private:
	void CleanUp()
	{

		vkDeviceWaitIdle(device);

		vkDestroyBuffer(device, indexBuffer, nullptr);
		vkFreeMemory(device, indexData, nullptr);

		for (int i = 0; i < 2; i++)
		{
			vkDestroyBuffer(device, vectorBuffer[i], nullptr);
			vkFreeMemory(device, vectorData[i], nullptr);
		}
		for (int i = 0; i < newLevel.myModel.size(); i++)
		{
			vkDestroyBuffer(device, newLevel.myModel[i].vertexBuffer, nullptr);
			vkFreeMemory(device, newLevel.myModel[i].vertexData, nullptr);
			vkDestroyBuffer(device, newLevel.myModel[i].indexBuffer, nullptr);
			vkFreeMemory(device, newLevel.myModel[i].indexData, nullptr);
		}
		vkDestroyBuffer(device, vertexHandle, nullptr);
		vkFreeMemory(device, vertexData, nullptr);
		vkDestroyShaderModule(device, vertexShader, nullptr);
		vkDestroyShaderModule(device, pixelShader, nullptr);

		vkDestroyDescriptorSetLayout(device, descripLayout, nullptr);

		vkDestroyDescriptorPool(device, descripPool, nullptr);
		vkDestroyPipelineLayout(device, pipelineLayout, nullptr);
		vkDestroyPipeline(device, pipeline, nullptr);
	}
};
