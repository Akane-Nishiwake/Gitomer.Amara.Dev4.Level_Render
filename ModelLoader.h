#pragma once
#include <vulkan/vulkan.h>
#include "Gateware.h"
#include <vector>
#include <fstream>
#include "h2bParser.h"
#include "FSLogo.h"
//loading model here
#define MAX_SUBMESH_PER_DRAW 1024
struct SHADER_MODEL_DATA
{
	GW::MATH::GVECTORF sunDirection, sunColor, sunAmbi;
	GW::MATH::GMATRIXF view, projection;

	GW::MATH::GMATRIXF matricies[MAX_SUBMESH_PER_DRAW];
	OBJ_ATTRIBUTES materials[MAX_SUBMESH_PER_DRAW];
};
class Level
{
	std::vector<Model> myModel;
	std::vector<Model> LoadFile(const char* level, std::vector<Model> model)
	{
		Model tempModel; //thing to store
		std::ifstream file;
		level = "GameLevel.txt";
		file.open(level, std::ios_base::in);
		if (file.is_open())
		{

			char buffer[128];
			std::string temp;
			file.getline(buffer, 128, '\n'); //header
			do
			{
				file.getline(buffer, 128, '\n'); //TYPE
				file.getline(buffer, 128, '\n'); //name
				GetMatrix(level, buffer, file, tempModel);

			} while (!file.eof());

		}
		file.close();
	}
	GW::MATH::GMATRIXF GetMatrix(const char* level, char* buffer, std::ifstream file, Model model)
	{
		// making the txt matrix into a float matrix
		Model tempModel = model; //thing to store
		for (int i = 0; i < 4; i++)
		{
			//row 1
			if (i = 0)
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				file.getline(buffer, 128, ','); // y  of matrix
				file.getline(buffer, 128, ','); // z of matrix
				file.getline(buffer, 128, ')'); // w and end of row matrix
			}
			//row 2
			else if (i = 1)
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				file.getline(buffer, 128, ','); // y  of matrix
				file.getline(buffer, 128, ','); // z of matrix
				file.getline(buffer, 128, ')'); // w and end of row matrix
			}
			//row 3
			else if (i = 2)
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				file.getline(buffer, 128, ','); // y  of matrix
				file.getline(buffer, 128, ','); // z of matrix
				file.getline(buffer, 128, ')'); // w and end of row matrix
			}
			//row 4
			else
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				file.getline(buffer, 128, ','); // y  of matrix
				file.getline(buffer, 128, ','); // z of matrix
				file.getline(buffer, 128, ')'); // w and end of row matrix
			}
			

		}
	}
};
class Model
{
	VkBuffer vertexBuffer = nullptr;
	VkDeviceMemory vertexData = nullptr;
	VkBuffer indexBuffer = nullptr;
	VkDeviceMemory indexData = nullptr;
	H2B::Parser parse;
	GW::MATH::GMATRIXF world;

	//this is where i will create a temporary
};