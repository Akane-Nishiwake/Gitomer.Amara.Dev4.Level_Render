// "Details_Basic_3.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Details_Basic_3.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Details_Basic_3_version_
const char Details_Basic_3_version[4] = { '0','1','9','d' };
#define _Details_Basic_3_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Details_Basic_3_vertexcount_
const unsigned Details_Basic_3_vertexcount = 96;
#define _Details_Basic_3_vertexcount_
#endif
#ifndef _Details_Basic_3_indexcount_
const unsigned Details_Basic_3_indexcount = 168;
#define _Details_Basic_3_indexcount_
#endif
#ifndef _Details_Basic_3_materialcount_
const unsigned Details_Basic_3_materialcount = 1; // can be used for batched draws
#define _Details_Basic_3_materialcount_
#endif
#ifndef _Details_Basic_3_meshcount_
const unsigned Details_Basic_3_meshcount = 1;
#define _Details_Basic_3_meshcount_
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
#ifndef _Details_Basic_3_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Details_Basic_3_vertices[96] =
{
	{	{ 0.062508f, 0.157530f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.953900f, -0.300300f }	},
	{	{ -0.062508f, 0.157530f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.953900f, -0.300300f }	},
	{	{ -0.068769f, 0.169550f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.953900f, -0.300300f }	},
	{	{ 0.068769f, 0.169550f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.953900f, -0.300300f }	},
	{	{ 0.140843f, -0.124155f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.938000f, 0.000000f, -0.346600f }	},
	{	{ 0.140843f, 0.079196f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.938000f, 0.000000f, -0.346600f }	},
	{	{ 0.154949f, 0.083369f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.938000f, 0.000000f, -0.346600f }	},
	{	{ 0.154949f, -0.140349f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.938000f, 0.000000f, -0.346600f }	},
	{	{ -0.121645f, -0.102117f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.836300f, -0.548300f }	},
	{	{ 0.121645f, -0.102117f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.836300f, -0.548300f }	},
	{	{ 0.127171f, -0.108461f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.836300f, -0.548300f }	},
	{	{ -0.127171f, -0.108461f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.836300f, -0.548300f }	},
	{	{ -0.154949f, -0.140349f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.938000f, 0.000000f, -0.346600f }	},
	{	{ -0.154949f, 0.083369f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.938000f, 0.000000f, -0.346600f }	},
	{	{ -0.140843f, 0.079195f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.938000f, 0.000000f, -0.346600f }	},
	{	{ -0.140843f, -0.124155f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.938000f, 0.000000f, -0.346600f }	},
	{	{ -0.140843f, -0.124155f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.920600f, -0.390400f }	},
	{	{ 0.140843f, -0.124155f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.920600f, -0.390400f }	},
	{	{ 0.154949f, -0.140349f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.920600f, -0.390400f }	},
	{	{ -0.154949f, -0.140349f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.920600f, -0.390400f }	},
	{	{ 0.154949f, -0.140349f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.154949f, 0.083369f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.068769f, 0.169550f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.154949f, -0.140349f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.154949f, 0.083369f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.068769f, 0.169550f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.140843f, 0.079195f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.669800f, 0.669800f, -0.320700f }	},
	{	{ -0.154949f, 0.083369f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.669800f, 0.669800f, -0.320700f }	},
	{	{ -0.068769f, 0.169550f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.669800f, 0.669800f, -0.320700f }	},
	{	{ -0.062508f, 0.157530f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.669800f, 0.669800f, -0.320700f }	},
	{	{ 0.154949f, 0.083369f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.669800f, 0.669800f, -0.320700f }	},
	{	{ 0.140843f, 0.079196f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.669800f, 0.669800f, -0.320700f }	},
	{	{ 0.062508f, 0.157530f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.669800f, 0.669800f, -0.320700f }	},
	{	{ 0.068769f, 0.169550f, 0.029228f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.669800f, 0.669800f, -0.320700f }	},
	{	{ -0.127171f, 0.075150f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000300f, -0.000100f, -1.000000f }	},
	{	{ -0.127171f, -0.108461f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000200f, 0.000100f, -1.000000f }	},
	{	{ -0.140843f, -0.124155f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000100f, 0.000100f, -1.000000f }	},
	{	{ -0.140843f, 0.079195f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000300f, -0.000100f, -1.000000f }	},
	{	{ 0.127171f, -0.108461f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000200f, 0.000100f, -1.000000f }	},
	{	{ 0.127171f, 0.075150f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000300f, -0.000100f, -1.000000f }	},
	{	{ 0.140843f, 0.079196f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000300f, -0.000100f, -1.000000f }	},
	{	{ 0.140843f, -0.124155f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000100f, 0.000100f, -1.000000f }	},
	{	{ 0.056440f, 0.145881f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000100f, -0.000300f, -1.000000f }	},
	{	{ 0.062508f, 0.157530f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000100f, -0.000300f, -1.000000f }	},
	{	{ -0.056440f, 0.145881f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000100f, -0.000300f, -1.000000f }	},
	{	{ -0.062508f, 0.157530f, -0.008955f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000100f, -0.000300f, -1.000000f }	},
	{	{ -0.115714f, 0.071761f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.907000f, 0.000000f, -0.421200f }	},
	{	{ -0.115714f, -0.095309f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.907000f, 0.000000f, -0.421200f }	},
	{	{ -0.121645f, -0.102117f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.907000f, 0.000000f, -0.421200f }	},
	{	{ -0.121645f, 0.073515f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.907000f, 0.000000f, -0.421200f }	},
	{	{ -0.121645f, 0.073515f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.868300f, -0.000000f, -0.496000f }	},
	{	{ -0.121645f, -0.102117f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.868300f, -0.000000f, -0.496000f }	},
	{	{ -0.127171f, -0.108461f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.868300f, -0.000000f, -0.496000f }	},
	{	{ -0.127171f, 0.075150f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.868300f, -0.000000f, -0.496000f }	},
	{	{ -0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.626500f, -0.626500f, -0.463700f }	},
	{	{ -0.121645f, 0.073515f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.626500f, -0.626500f, -0.463700f }	},
	{	{ -0.127171f, 0.075150f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.626500f, -0.626500f, -0.463700f }	},
	{	{ -0.056440f, 0.145881f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.626500f, -0.626500f, -0.463700f }	},
	{	{ 0.121645f, -0.102117f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.868300f, 0.000000f, -0.496000f }	},
	{	{ 0.121645f, 0.073515f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.868300f, 0.000000f, -0.496000f }	},
	{	{ 0.127171f, 0.075150f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.868300f, 0.000000f, -0.496000f }	},
	{	{ 0.127171f, -0.108461f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.868300f, 0.000000f, -0.496000f }	},
	{	{ 0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.899200f, -0.437600f }	},
	{	{ -0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.899200f, -0.437600f }	},
	{	{ -0.056440f, 0.145881f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.899200f, -0.437600f }	},
	{	{ 0.056440f, 0.145881f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.899200f, -0.437600f }	},
	{	{ 0.121645f, 0.073515f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.626500f, -0.626500f, -0.463700f }	},
	{	{ 0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.626500f, -0.626500f, -0.463700f }	},
	{	{ 0.056440f, 0.145881f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.626500f, -0.626500f, -0.463700f }	},
	{	{ 0.127171f, 0.075150f, -0.008951f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.626500f, -0.626500f, -0.463700f }	},
	{	{ -0.115714f, -0.095309f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.115714f, 0.071761f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ -0.051356f, 0.136119f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.115714f, -0.095309f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.115714f, 0.071761f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.051355f, 0.136119f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, -0.000000f, -1.000000f }	},
	{	{ 0.115714f, 0.071761f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.650600f, 0.650600f, -0.391600f }	},
	{	{ 0.051355f, 0.136119f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.650600f, 0.650600f, -0.391600f }	},
	{	{ 0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.650600f, 0.650600f, -0.391600f }	},
	{	{ 0.121645f, 0.073515f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.650600f, 0.650600f, -0.391600f }	},
	{	{ 0.115714f, -0.095309f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.906900f, 0.000000f, -0.421200f }	},
	{	{ 0.115714f, 0.071761f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.906900f, 0.000000f, -0.421200f }	},
	{	{ 0.121645f, 0.073515f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.906900f, 0.000000f, -0.421200f }	},
	{	{ 0.121645f, -0.102117f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.906900f, 0.000000f, -0.421200f }	},
	{	{ -0.051356f, 0.136119f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.650600f, 0.650600f, -0.391600f }	},
	{	{ -0.115714f, 0.071761f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.650600f, 0.650600f, -0.391600f }	},
	{	{ -0.121645f, 0.073515f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.650600f, 0.650600f, -0.391600f }	},
	{	{ -0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.650600f, 0.650600f, -0.391600f }	},
	{	{ -0.115714f, -0.095309f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.882400f, -0.470500f }	},
	{	{ 0.115714f, -0.095309f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.882400f, -0.470500f }	},
	{	{ 0.121645f, -0.102117f, 0.000723f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.882400f, -0.470500f }	},
	{	{ -0.121645f, -0.102117f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.882400f, -0.470500f }	},
	{	{ 0.051355f, 0.136119f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.929800f, -0.368000f }	},
	{	{ -0.051356f, 0.136119f, -0.012046f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.929800f, -0.368000f }	},
	{	{ -0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.929800f, -0.368000f }	},
	{	{ 0.053988f, 0.141172f, 0.000724f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.929800f, -0.368000f }	},
};
#define _Details_Basic_3_vertices_
#endif
#ifndef _Details_Basic_3_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Details_Basic_3_indices[168] =
{
	 0, 1, 2,
	 3, 0, 2,
	 4, 5, 6,
	 7, 4, 6,
	 8, 9, 10,
	 11, 8, 10,
	 12, 13, 14,
	 15, 12, 14,
	 16, 17, 18,
	 19, 16, 18,
	 20, 21, 22,
	 23, 20, 22,
	 24, 23, 22,
	 25, 24, 22,
	 26, 27, 28,
	 29, 26, 28,
	 30, 31, 32,
	 33, 30, 32,
	 34, 35, 36,
	 37, 34, 36,
	 38, 39, 40,
	 41, 38, 40,
	 39, 42, 43,
	 40, 39, 43,
	 44, 34, 37,
	 45, 44, 37,
	 42, 44, 45,
	 43, 42, 45,
	 35, 38, 41,
	 36, 35, 41,
	 46, 47, 48,
	 49, 46, 48,
	 50, 51, 52,
	 53, 50, 52,
	 54, 55, 56,
	 57, 54, 56,
	 58, 59, 60,
	 61, 58, 60,
	 62, 63, 64,
	 65, 62, 64,
	 66, 67, 68,
	 69, 66, 68,
	 70, 71, 72,
	 73, 70, 72,
	 74, 73, 72,
	 75, 74, 72,
	 76, 77, 78,
	 79, 76, 78,
	 80, 81, 82,
	 83, 80, 82,
	 84, 85, 86,
	 87, 84, 86,
	 88, 89, 90,
	 91, 88, 90,
	 92, 93, 94,
	 95, 92, 94,
};
#define _Details_Basic_3_indices_
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
#ifndef _Details_Basic_3_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Details_Basic_3_materials[1] =
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
#define _Details_Basic_3_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Details_Basic_3_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Details_Basic_3_batches[1][2] =
{
	{ 168, 0 },
};
#define _Details_Basic_3_batches_
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
#ifndef _Details_Basic_3_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Details_Basic_3_meshes[1] =
{
	{
		"default",
		168,
		0,
		0,
	},
};
#define _Details_Basic_3_meshes_
#endif
