// "Details_Arrow_2.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Details_Arrow_2.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Details_Arrow_2_version_
const char Details_Arrow_2_version[4] = { '0','1','9','d' };
#define _Details_Arrow_2_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Details_Arrow_2_vertexcount_
const unsigned Details_Arrow_2_vertexcount = 76;
#define _Details_Arrow_2_vertexcount_
#endif
#ifndef _Details_Arrow_2_indexcount_
const unsigned Details_Arrow_2_indexcount = 162;
#define _Details_Arrow_2_indexcount_
#endif
#ifndef _Details_Arrow_2_materialcount_
const unsigned Details_Arrow_2_materialcount = 1; // can be used for batched draws
#define _Details_Arrow_2_materialcount_
#endif
#ifndef _Details_Arrow_2_meshcount_
const unsigned Details_Arrow_2_meshcount = 1;
#define _Details_Arrow_2_meshcount_
#endif
/************************************************/
/*  This section contains the raw data to load  */
/************************************************/
#ifndef __OBJ_VEC3__
typedef struct _OBJ_VEC3_
{
	float x,y,z; // 3D Coordinate.
}OBJ_VEC3;
#define __OBJ_VEC3__
#endif
#ifndef __OBJ_VERT__
typedef struct _OBJ_VERT_
{
	OBJ_VEC3 pos; // Left-handed +Z forward coordinate w not provided, assumed to be 1.
	OBJ_VEC3 uvw; // D3D/Vulkan style top left 0,0 coordinate.
	OBJ_VEC3 nrm; // Provided direct from obj file, may or may not be normalized.
}OBJ_VERT;
#define __OBJ_VERT__
#endif
#ifndef _Details_Arrow_2_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Details_Arrow_2_vertices[76] =
{
	{	{ -0.054682f, 0.036345f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.701600f, 0.700700f, -0.129400f }	},
	{	{ 0.000081f, 0.091072f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.701100f, 0.701300f, -0.129100f }	},
	{	{ 0.000081f, 0.077680f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.701100f, 0.701300f, -0.129100f }	},
	{	{ -0.051431f, 0.026168f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.701700f, 0.700600f, -0.129400f }	},
	{	{ 0.183273f, -0.091997f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.701000f, 0.701300f, -0.129700f }	},
	{	{ 0.171896f, -0.094135f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.701000f, 0.701300f, -0.129700f }	},
	{	{ 0.051592f, 0.026169f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.701000f, 0.701300f, -0.129400f }	},
	{	{ 0.054843f, 0.036345f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.701000f, 0.701300f, -0.129400f }	},
	{	{ 0.121553f, -0.131460f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.158670f, -0.094343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.171896f, -0.094135f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.120384f, -0.145647f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.000081f, 0.077680f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.701100f, 0.701300f, -0.129100f }	},
	{	{ 0.000081f, 0.091072f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.701100f, 0.701300f, -0.129100f }	},
	{	{ 0.120384f, -0.145647f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.716600f, -0.688600f, -0.111500f }	},
	{	{ 0.171896f, -0.094135f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.716600f, -0.688600f, -0.111500f }	},
	{	{ 0.183273f, -0.091997f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.716600f, -0.688600f, -0.111500f }	},
	{	{ 0.120986f, -0.158913f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.716600f, -0.688600f, -0.111500f }	},
	{	{ -0.037036f, 0.027129f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.158508f, -0.094343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.064000f, 0.064000f, -0.995900f }	},
	{	{ -0.172627f, -0.095473f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.051431f, 0.026168f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.120384f, -0.145647f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.699200f, -0.703200f, -0.128900f }	},
	{	{ 0.120986f, -0.158913f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.699200f, -0.703200f, -0.128900f }	},
	{	{ 0.000081f, -0.039384f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.699200f, -0.703200f, -0.128900f }	},
	{	{ 0.000081f, -0.025343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.699200f, -0.703200f, -0.128900f }	},
	{	{ -0.172627f, -0.095473f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.716600f, -0.688600f, -0.111500f }	},
	{	{ -0.121115f, -0.146985f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.716600f, -0.688600f, -0.111500f }	},
	{	{ -0.121717f, -0.160251f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.716600f, -0.688600f, -0.111500f }	},
	{	{ -0.184004f, -0.093335f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.716600f, -0.688600f, -0.111500f }	},
	{	{ -0.172627f, -0.095473f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.702300f, 0.700000f, -0.129700f }	},
	{	{ -0.184004f, -0.093335f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.702300f, 0.700000f, -0.129700f }	},
	{	{ -0.121717f, -0.160251f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.700500f, -0.701900f, -0.128700f }	},
	{	{ -0.121115f, -0.146985f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.700500f, -0.701900f, -0.128700f }	},
	{	{ 0.000081f, -0.025343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.700500f, -0.701900f, -0.128700f }	},
	{	{ 0.000081f, -0.039384f, 0.052246f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.700500f, -0.701900f, -0.128700f }	},
	{	{ 0.001286f, -0.011193f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.000081f, -0.025343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.138483f, -0.088800f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.192100f, 0.192100f, -0.962400f }	},
	{	{ -0.115365f, -0.111918f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.193700f, 0.193700f, -0.961800f }	},
	{	{ -0.120187f, -0.132665f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.062100f, 0.062100f, -0.996100f }	},
	{	{ -0.115365f, -0.111918f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.457600f, 0.457600f, -0.762300f }	},
	{	{ -0.001857f, 0.001590f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.457600f, 0.457600f, -0.762300f }	},
	{	{ 0.001286f, -0.011193f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.457600f, 0.457600f, -0.762300f }	},
	{	{ -0.120187f, -0.132665f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.457600f, 0.457600f, -0.762300f }	},
	{	{ 0.000332f, 0.050015f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.482600f, -0.482600f, -0.730900f }	},
	{	{ -0.024975f, 0.024708f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.482600f, -0.482600f, -0.730900f }	},
	{	{ -0.037036f, 0.027129f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.482600f, -0.482600f, -0.730900f }	},
	{	{ 0.000081f, 0.064246f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.482600f, -0.482600f, -0.730900f }	},
	{	{ 0.038402f, 0.025924f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.000081f, 0.064246f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.000081f, 0.077680f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.051592f, 0.026169f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.121115f, -0.146985f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.024975f, 0.024708f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.000332f, 0.050015f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.023450f, 0.026897f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.001857f, 0.001590f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.140111f, -0.089763f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.114804f, -0.115070f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.140111f, -0.089763f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.491600f, -0.491600f, -0.718800f }	},
	{	{ 0.023450f, 0.026897f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.491600f, -0.491600f, -0.718800f }	},
	{	{ 0.038402f, 0.025924f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.491600f, -0.491600f, -0.718800f }	},
	{	{ 0.158670f, -0.094343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.491600f, -0.491600f, -0.718800f }	},
	{	{ 0.000332f, 0.050015f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.491600f, -0.491600f, -0.718800f }	},
	{	{ 0.000081f, 0.064246f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.491600f, -0.491600f, -0.718800f }	},
	{	{ -0.138483f, -0.088800f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.482600f, -0.482600f, -0.730900f }	},
	{	{ -0.158508f, -0.094343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.482600f, -0.482600f, -0.730900f }	},
	{	{ -0.001857f, 0.001590f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.575700f, 0.575700f, -0.580600f }	},
	{	{ 0.114804f, -0.115070f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.575700f, 0.575700f, -0.580600f }	},
	{	{ 0.121553f, -0.131460f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.575700f, 0.575700f, -0.580600f }	},
	{	{ 0.001286f, -0.011193f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.575700f, 0.575700f, -0.580600f }	},
	{	{ 0.114804f, -0.115070f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.356700f, 0.356700f, -0.863400f }	},
	{	{ 0.140111f, -0.089763f, -0.011042f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.356700f, 0.356700f, -0.863400f }	},
	{	{ 0.158670f, -0.094343f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.356700f, 0.356700f, -0.863400f }	},
	{	{ 0.121553f, -0.131460f, -0.020602f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.356700f, 0.356700f, -0.863400f }	},
};
#define _Details_Arrow_2_vertices_
#endif
#ifndef _Details_Arrow_2_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Details_Arrow_2_indices[162] =
{
	 0, 1, 2,
	 3, 0, 2,
	 4, 5, 6,
	 7, 4, 6,
	 8, 9, 10,
	 11, 8, 10,
	 6, 12, 13,
	 7, 6, 13,
	 14, 15, 16,
	 17, 14, 16,
	 18, 19, 20,
	 21, 18, 20,
	 22, 23, 24,
	 25, 22, 24,
	 26, 27, 28,
	 29, 26, 28,
	 30, 31, 0,
	 3, 30, 0,
	 32, 33, 34,
	 35, 32, 34,
	 36, 8, 11,
	 37, 36, 11,
	 38, 39, 40,
	 19, 38, 40,
	 41, 42, 43,
	 44, 41, 43,
	 45, 46, 47,
	 48, 45, 47,
	 49, 50, 51,
	 52, 49, 51,
	 40, 36, 37,
	 53, 40, 37,
	 9, 49, 52,
	 10, 9, 52,
	 19, 40, 53,
	 20, 19, 53,
	 50, 18, 21,
	 51, 50, 21,
	 54, 55, 56,
	 57, 54, 56,
	 58, 59, 57,
	 56, 58, 57,
	 39, 38, 54,
	 57, 39, 54,
	 60, 61, 62,
	 63, 60, 62,
	 61, 64, 65,
	 62, 61, 65,
	 46, 66, 67,
	 47, 46, 67,
	 68, 69, 70,
	 71, 68, 70,
	 72, 73, 74,
	 75, 72, 74,
};
#define _Details_Arrow_2_indices_
#endif
// Part of an OBJ_MATERIAL, the struct is 16 byte aligned so it is GPU register friendly.
#ifndef __OBJ_ATTRIBUTES__
typedef struct _OBJ_ATTRIBUTES_
{
	OBJ_VEC3    Kd; // diffuse reflectivity
	float	    d; // dissolve (transparency) 
	OBJ_VEC3    Ks; // specular reflectivity
	float       Ns; // specular exponent
	OBJ_VEC3    Ka; // ambient reflectivity
	float       sharpness; // local reflection map sharpness
	OBJ_VEC3    Tf; // transmission filter
	float       Ni; // optical density (index of refraction)
	OBJ_VEC3    Ke; // emissive reflectivity
	unsigned    illum; // illumination model
}OBJ_ATTRIBUTES;
#define __OBJ_ATTRIBUTES__
#endif
// This structure also has been made GPU register friendly so it can be transfered directly if desired.
// Note: Total struct size will vary depenedening on CPU processor architecture (string pointers).
#ifndef __OBJ_MATERIAL__
typedef struct _OBJ_MATERIAL_
{
	// The following items are typically used in a pixel/fragment shader, they are packed for GPU registers.
	OBJ_ATTRIBUTES attrib; // Surface shading characteristics & illumination model
	// All items below this line are not needed on the GPU and are generally only used during load time.
	const char* name; // the name of this material
	// If the model's materials contain any specific texture data it will be located below.
	const char* map_Kd; // diffuse texture
	const char* map_Ks; // specular texture
	const char* map_Ka; // ambient texture
	const char* map_Ke; // emissive texture
	const char* map_Ns; // specular exponent texture
	const char* map_d; // transparency texture
	const char* disp; // roughness map (displacement)
	const char* decal; // decal texture (lerps texture & material colors)
	const char* bump; // normal/bumpmap texture
	void* padding[2]; // 16 byte alignment on 32bit or 64bit
}OBJ_MATERIAL;
#define __OBJ_MATERIAL__
#endif
#ifndef _Details_Arrow_2_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Details_Arrow_2_materials[1] =
{
	{
		{{ 0.321571f, 0.321571f, 0.321571f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078430f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Main",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
		"",
	},
};
#define _Details_Arrow_2_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Details_Arrow_2_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Details_Arrow_2_batches[1][2] =
{
	{ 162, 0 },
};
#define _Details_Arrow_2_batches_
#endif
#ifndef __OBJ_MESH__
typedef struct _OBJ_MESH_
{
	const char* name;
	unsigned    indexCount;
	unsigned    indexOffset;
	unsigned    materialIndex;
}OBJ_MESH;
#define __OBJ_MESH__
#endif
#ifndef _Details_Arrow_2_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Details_Arrow_2_meshes[1] =
{
	{
		"default",
		162,
		0,
		0,
	},
};
#define _Details_Arrow_2_meshes_
#endif
