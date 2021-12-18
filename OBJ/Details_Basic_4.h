// "Details_Basic_4.h" generated by "Obj2Header.exe" [Version 1.9d] Author: L.Norri Fullsail University.
// Data is converted to left-handed coordinate system and UV data is V flipped for Direct3D/Vulkan.
// The companion file "Details_Basic_4.h2b" is a binary dump of this format(-padding) for more flexibility.
// Loading *.h2b: read version, sizes, handle strings(max len 260) by reading until null-terminated.
/***********************/
/*  Generator version  */
/***********************/
#ifndef _Details_Basic_4_version_
const char Details_Basic_4_version[4] = { '0','1','9','d' };
#define _Details_Basic_4_version_
#endif
/************************************************/
/*  This section contains the model's size data */
/************************************************/
#ifndef _Details_Basic_4_vertexcount_
const unsigned Details_Basic_4_vertexcount = 208;
#define _Details_Basic_4_vertexcount_
#endif
#ifndef _Details_Basic_4_indexcount_
const unsigned Details_Basic_4_indexcount = 420;
#define _Details_Basic_4_indexcount_
#endif
#ifndef _Details_Basic_4_materialcount_
const unsigned Details_Basic_4_materialcount = 2; // can be used for batched draws
#define _Details_Basic_4_materialcount_
#endif
#ifndef _Details_Basic_4_meshcount_
const unsigned Details_Basic_4_meshcount = 2;
#define _Details_Basic_4_meshcount_
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
#ifndef _Details_Basic_4_vertices_
// Raw Vertex Data follows: Positions, Texture Coordinates and Normals.
const OBJ_VERT Details_Basic_4_vertices[208] =
{
	{	{ 0.277018f, 0.111373f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.208486f, 0.175529f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.229362f, 0.202653f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.303431f, 0.128584f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.303432f, -0.134601f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.303432f, -0.035013f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.339738f, -0.039202f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.339738f, -0.150707f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ -0.191392f, 0.156800f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.963800f, -0.266800f }	},
	{	{ 0.191392f, 0.156800f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.963800f, -0.266800f }	},
	{	{ 0.186476f, 0.153606f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.963800f, -0.266800f }	},
	{	{ -0.186476f, 0.153606f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.963800f, -0.266800f }	},
	{	{ 0.229362f, 0.202653f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.942000f, -0.335700f }	},
	{	{ -0.229362f, 0.202653f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.942000f, -0.335700f }	},
	{	{ -0.256806f, 0.226902f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.942000f, -0.335700f }	},
	{	{ 0.256806f, 0.226902f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.942000f, -0.335700f }	},
	{	{ -0.339738f, -0.150706f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ -0.339738f, -0.039202f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ -0.303432f, -0.035013f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ -0.303432f, -0.134601f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.256806f, -0.233639f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.339738f, -0.150707f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.339738f, -0.039202f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.256806f, -0.233639f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.339738f, -0.150706f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.339738f, -0.039202f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.339738f, -0.150706f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.621000f, -0.621000f, -0.478400f }	},
	{	{ -0.303432f, -0.134601f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.621000f, -0.621000f, -0.478400f }	},
	{	{ -0.229362f, -0.208671f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.621000f, -0.621000f, -0.478400f }	},
	{	{ -0.256806f, -0.233639f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.621000f, -0.621000f, -0.478400f }	},
	{	{ -0.303432f, 0.128584f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.622900f, 0.622900f, -0.473300f }	},
	{	{ -0.339738f, 0.143969f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.622900f, 0.622900f, -0.473300f }	},
	{	{ -0.256806f, 0.226902f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.622900f, 0.622900f, -0.473300f }	},
	{	{ -0.229362f, 0.202653f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.622900f, 0.622900f, -0.473300f }	},
	{	{ 0.303432f, -0.134601f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.621000f, -0.621000f, -0.478400f }	},
	{	{ 0.339738f, -0.150707f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.621000f, -0.621000f, -0.478400f }	},
	{	{ 0.256806f, -0.233639f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.621000f, -0.621000f, -0.478400f }	},
	{	{ 0.229362f, -0.208671f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.621000f, -0.621000f, -0.478400f }	},
	{	{ 0.339738f, 0.143969f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.622900f, 0.622900f, -0.473300f }	},
	{	{ 0.303431f, 0.128584f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.622900f, 0.622900f, -0.473300f }	},
	{	{ 0.229362f, 0.202653f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.622900f, 0.622900f, -0.473300f }	},
	{	{ 0.256806f, 0.226902f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.622900f, 0.622900f, -0.473300f }	},
	{	{ -0.229362f, -0.208671f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.938800f, -0.344500f }	},
	{	{ 0.229362f, -0.208671f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.938800f, -0.344500f }	},
	{	{ 0.256806f, -0.233639f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.938800f, -0.344500f }	},
	{	{ -0.256806f, -0.233639f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.938800f, -0.344500f }	},
	{	{ 0.339738f, 0.052678f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.339738f, 0.052678f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.208486f, -0.180741f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.208486f, -0.180741f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.229362f, -0.208671f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.229362f, -0.208671f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.339738f, 0.052678f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ -0.303432f, 0.047049f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.303432f, 0.047049f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.339738f, 0.052678f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.277018f, 0.040752f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.303432f, 0.047049f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.339738f, 0.143969f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ -0.303432f, 0.128584f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.303431f, 0.128584f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.339738f, 0.143969f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.882200f, 0.000000f, -0.470800f }	},
	{	{ 0.256806f, 0.226902f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.256806f, 0.226902f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.339738f, 0.143969f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ 0.339738f, 0.143969f, 0.052848f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.000000f, 1.000000f }	},
	{	{ -0.201329f, 0.170666f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.551600f, -0.589200f, -0.590400f }	},
	{	{ -0.267962f, 0.108288f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.551600f, -0.589200f, -0.590400f }	},
	{	{ -0.277018f, 0.111373f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.551600f, -0.589200f, -0.590400f }	},
	{	{ -0.208486f, 0.175529f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.551600f, -0.589200f, -0.590400f }	},
	{	{ 0.255389f, 0.099490f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.255389f, 0.036403f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.249170f, 0.035662f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.249170f, 0.097463f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ -0.208486f, 0.175529f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.229362f, 0.202653f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.277018f, 0.111373f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.303432f, 0.128584f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.277018f, -0.116585f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.277018f, -0.030326f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.303432f, -0.035013f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.303432f, -0.134601f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.277018f, 0.040751f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.303432f, 0.047049f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.277018f, -0.030326f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.303432f, -0.035013f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.277018f, -0.116585f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.303432f, -0.134601f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.249170f, -0.102024f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.249170f, -0.026539f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.249170f, -0.026538f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.186476f, -0.158166f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.186476f, -0.158166f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.249170f, -0.102024f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.249170f, 0.035662f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.249170f, 0.035662f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.249170f, 0.097463f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.186476f, 0.153606f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.186476f, 0.153606f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.249170f, 0.097463f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.267963f, -0.113355f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.549200f, 0.586700f, -0.595100f }	},
	{	{ -0.201329f, -0.175734f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.549200f, 0.586700f, -0.595100f }	},
	{	{ -0.208486f, -0.180741f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.549200f, 0.586700f, -0.595100f }	},
	{	{ -0.277018f, -0.116585f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.549200f, 0.586700f, -0.595100f }	},
	{	{ -0.255389f, -0.104146f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ -0.255389f, -0.027091f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ -0.249170f, -0.026539f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ -0.249170f, -0.102024f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ 0.201329f, 0.170666f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.921500f, -0.388300f }	},
	{	{ -0.201329f, 0.170666f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.921500f, -0.388300f }	},
	{	{ -0.208486f, 0.175529f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.921500f, -0.388300f }	},
	{	{ 0.208486f, 0.175529f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.921500f, -0.388300f }	},
	{	{ -0.255389f, 0.036403f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ -0.255389f, 0.099490f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ -0.249170f, 0.097463f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ -0.249170f, 0.035662f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.880300f, -0.000000f, -0.474400f }	},
	{	{ 0.255389f, -0.027090f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.255389f, -0.104146f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.249170f, -0.102024f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.249170f, -0.026538f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.880300f, 0.000000f, -0.474400f }	},
	{	{ 0.267962f, 0.039623f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.267962f, 0.108288f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.277018f, 0.111373f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.277018f, 0.040752f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.191392f, -0.161456f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.961700f, -0.274100f }	},
	{	{ -0.191392f, -0.161456f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.961700f, -0.274100f }	},
	{	{ -0.186476f, -0.158166f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.961700f, -0.274100f }	},
	{	{ 0.186476f, -0.158166f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, -0.961700f, -0.274100f }	},
	{	{ -0.191392f, -0.161456f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.597500f, -0.667200f, -0.444700f }	},
	{	{ -0.255389f, -0.104146f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.597500f, -0.667200f, -0.444700f }	},
	{	{ -0.249170f, -0.102024f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.597500f, -0.667200f, -0.444700f }	},
	{	{ -0.186476f, -0.158166f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.597500f, -0.667200f, -0.444700f }	},
	{	{ -0.255389f, -0.027091f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.151200f, -0.988500f, -0.006200f }	},
	{	{ -0.267962f, -0.029486f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.151200f, -0.988500f, -0.006200f }	},
	{	{ -0.277018f, -0.030326f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.151200f, -0.988500f, -0.006200f }	},
	{	{ -0.249170f, -0.026539f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.151200f, -0.988500f, -0.006200f }	},
	{	{ 0.201329f, -0.175734f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.549200f, 0.586700f, -0.595100f }	},
	{	{ 0.267962f, -0.113355f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.549200f, 0.586700f, -0.595100f }	},
	{	{ 0.277018f, -0.116585f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.549200f, 0.586700f, -0.595100f }	},
	{	{ 0.208486f, -0.180741f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.549200f, 0.586700f, -0.595100f }	},
	{	{ -0.255389f, 0.099490f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.599000f, 0.668900f, -0.440300f }	},
	{	{ -0.191392f, 0.156800f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.599000f, 0.668900f, -0.440300f }	},
	{	{ -0.186476f, 0.153606f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.599000f, 0.668900f, -0.440300f }	},
	{	{ -0.249170f, 0.097463f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.599000f, 0.668900f, -0.440300f }	},
	{	{ -0.267962f, 0.039622f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.201300f, 0.979500f, -0.008300f }	},
	{	{ -0.255389f, 0.036403f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.201300f, 0.979500f, -0.008300f }	},
	{	{ -0.249170f, 0.035662f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.201300f, 0.979500f, -0.008300f }	},
	{	{ -0.277018f, 0.040751f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.201300f, 0.979500f, -0.008300f }	},
	{	{ 0.267962f, 0.108288f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.551600f, -0.589200f, -0.590400f }	},
	{	{ 0.201329f, 0.170666f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.551600f, -0.589200f, -0.590400f }	},
	{	{ 0.208486f, 0.175529f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.551600f, -0.589200f, -0.590400f }	},
	{	{ 0.277018f, 0.111373f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.551600f, -0.589200f, -0.590400f }	},
	{	{ 0.255389f, -0.104146f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.597500f, -0.667200f, -0.444700f }	},
	{	{ 0.191392f, -0.161456f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.597500f, -0.667200f, -0.444700f }	},
	{	{ 0.186476f, -0.158166f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.597500f, -0.667200f, -0.444700f }	},
	{	{ 0.249170f, -0.102024f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.597500f, -0.667200f, -0.444700f }	},
	{	{ 0.255389f, 0.036403f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.201300f, 0.979500f, -0.008300f }	},
	{	{ 0.267962f, 0.039623f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.201300f, 0.979500f, -0.008300f }	},
	{	{ 0.277018f, 0.040752f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.201300f, 0.979500f, -0.008300f }	},
	{	{ 0.249170f, 0.035662f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.201300f, 0.979500f, -0.008300f }	},
	{	{ -0.201329f, -0.175734f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.917400f, -0.398000f }	},
	{	{ 0.201329f, -0.175734f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.917400f, -0.398000f }	},
	{	{ 0.208486f, -0.180741f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.917400f, -0.398000f }	},
	{	{ -0.208486f, -0.180741f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.000000f, 0.917400f, -0.398000f }	},
	{	{ 0.267962f, -0.113355f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.267962f, -0.029486f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.277018f, -0.030326f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.277018f, -0.116585f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.191392f, 0.156800f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.599000f, 0.668900f, -0.440300f }	},
	{	{ 0.255389f, 0.099490f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.599000f, 0.668900f, -0.440300f }	},
	{	{ 0.249170f, 0.097463f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.599000f, 0.668900f, -0.440300f }	},
	{	{ 0.186476f, 0.153606f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.599000f, 0.668900f, -0.440300f }	},
	{	{ -0.267962f, 0.108288f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ -0.267962f, 0.039622f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ -0.277018f, 0.040751f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ -0.277018f, 0.111373f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.267962f, -0.029486f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.151200f, -0.988500f, -0.006200f }	},
	{	{ 0.255389f, -0.027090f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.151200f, -0.988500f, -0.006200f }	},
	{	{ 0.249170f, -0.026538f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.151200f, -0.988500f, -0.006200f }	},
	{	{ 0.277018f, -0.030326f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ -0.151200f, -0.988500f, -0.006200f }	},
	{	{ -0.267962f, -0.029486f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ -0.267963f, -0.113355f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ -0.277018f, -0.116585f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ -0.277018f, -0.030326f, -0.015186f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.786700f, 0.000000f, -0.617300f }	},
	{	{ 0.255389f, -0.104146f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.255389f, -0.027090f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.267962f, -0.029486f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.267962f, -0.113355f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.191392f, 0.156800f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.191392f, 0.156800f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.201329f, 0.170666f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.201329f, 0.170666f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.255389f, -0.104146f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.191392f, -0.161456f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.201329f, -0.175734f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.267963f, -0.113355f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.191392f, -0.161456f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.201329f, -0.175734f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.255389f, 0.099490f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.267962f, 0.108288f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.255389f, -0.027091f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.267962f, -0.029486f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.255389f, 0.036403f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ -0.267962f, 0.039622f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.255389f, 0.036403f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.255389f, 0.099490f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.267962f, 0.108288f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
	{	{ 0.267962f, 0.039623f, -0.003645f },	{ 0.000000f, 0.000000f, 0.000000f },	{ 0.000000f, 0.000000f, -1.000000f }	},
};
#define _Details_Basic_4_vertices_
#endif
#ifndef _Details_Basic_4_indices_
// Index Data follows: Sequential by mesh, Every Three Indices == One Triangle.
const unsigned int Details_Basic_4_indices[420] =
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
	 42, 43, 44,
	 45, 42, 44,
	 46, 47, 25,
	 22, 46, 25,
	 48, 49, 50,
	 51, 48, 50,
	 52, 53, 18,
	 17, 52, 18,
	 54, 55, 6,
	 5, 54, 6,
	 56, 0, 3,
	 57, 56, 3,
	 58, 59, 53,
	 52, 58, 53,
	 60, 61, 55,
	 54, 60, 55,
	 62, 63, 64,
	 65, 62, 64,
	 46, 65, 64,
	 47, 46, 64,
	 66, 67, 68,
	 69, 66, 68,
	 70, 71, 72,
	 73, 70, 72,
	 1, 74, 75,
	 2, 1, 75,
	 74, 76, 77,
	 75, 74, 77,
	 78, 79, 80,
	 81, 78, 80,
	 76, 82, 83,
	 77, 76, 83,
	 78, 81, 50,
	 49, 78, 50,
	 79, 56, 57,
	 80, 79, 57,
	 82, 84, 85,
	 83, 82, 85,
	 84, 86, 87,
	 85, 84, 87,
	 86, 48, 51,
	 87, 86, 51,
	 88, 89, 90,
	 91, 88, 90,
	 92, 91, 90,
	 93, 92, 90,
	 94, 95, 90,
	 89, 94, 90,
	 96, 97, 98,
	 94, 96, 98,
	 95, 94, 98,
	 99, 95, 98,
	 100, 101, 102,
	 103, 100, 102,
	 104, 105, 106,
	 107, 104, 106,
	 108, 109, 110,
	 111, 108, 110,
	 112, 113, 114,
	 115, 112, 114,
	 94, 89, 84,
	 82, 94, 84,
	 116, 117, 118,
	 119, 116, 118,
	 90, 95, 56,
	 79, 90, 56,
	 120, 121, 122,
	 123, 120, 122,
	 124, 125, 126,
	 127, 124, 126,
	 128, 129, 130,
	 131, 128, 130,
	 132, 133, 134,
	 135, 132, 134,
	 136, 137, 138,
	 139, 136, 138,
	 140, 141, 142,
	 143, 140, 142,
	 144, 145, 146,
	 147, 144, 146,
	 148, 149, 150,
	 151, 148, 150,
	 152, 153, 154,
	 155, 152, 154,
	 156, 157, 158,
	 159, 156, 158,
	 160, 161, 162,
	 163, 160, 162,
	 164, 165, 166,
	 167, 164, 166,
	 168, 169, 170,
	 171, 168, 170,
	 172, 173, 174,
	 175, 172, 174,
	 176, 177, 178,
	 179, 176, 178,
	 180, 181, 182,
	 183, 180, 182,
	 184, 185, 186,
	 187, 184, 186,
	 188, 189, 190,
	 191, 188, 190,
	 192, 193, 194,
	 195, 192, 194,
	 193, 196, 197,
	 194, 193, 197,
	 189, 198, 199,
	 190, 189, 199,
	 200, 192, 195,
	 201, 200, 195,
	 198, 202, 203,
	 199, 198, 203,
	 196, 184, 187,
	 197, 196, 187,
	 204, 205, 206,
	 207, 204, 206,
	 205, 188, 191,
	 206, 205, 191,
};
#define _Details_Basic_4_indices_
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
#ifndef _Details_Basic_4_materials_
// Material Data follows: pulled from a .mtl file of the same name if present.
const OBJ_MATERIAL Details_Basic_4_materials[2] =
{
	{
		{{ 0.447674f, 0.238138f, 0.053432f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078430f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"Accent",
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
	{
		{{ 0.181263f, 0.098703f, 0.024118f },
		1.000000f,
		{ 0.500000f, 0.500000f, 0.500000f },
		96.078430f,
		{ 1.000000f, 1.000000f, 1.000000f },
		60.000000f,
		{ 1.000000f, 1.000000f, 1.000000f },
		1.000000f,
		{ 0.000000f, 0.000000f, 0.000000f },
		2},
		"DarkAccent",
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
#define _Details_Basic_4_materials_
#endif
/************************************************/
/*  This section contains the model's structure */
/************************************************/
#ifndef _Details_Basic_4_batches_
// Use this conveinence array to batch render all geometry by like material.
// Each entry corresponds to the same entry in the materials array above.
// The two numbers provided are the IndexCount and the IndexOffset into the indices array.
// If you need more fine grained control(ex: for transformations) use the OBJ_MESH data below.
const unsigned int Details_Basic_4_batches[2][2] =
{
	{ 360, 0 },
	{ 60, 360 },
};
#define _Details_Basic_4_batches_
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
#ifndef _Details_Basic_4_meshes_
// Mesh Data follows: Meshes are .obj groups sorted & split by material.
// Meshes are provided in sequential order, sorted by material first and name second.
const OBJ_MESH Details_Basic_4_meshes[2] =
{
	{
		"default",
		360,
		0,
		0,
	},
	{
		"default",
		60,
		360,
		1,
	},
};
#define _Details_Basic_4_meshes_
#endif
