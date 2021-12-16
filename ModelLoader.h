#pragma once
#include <vulkan/vulkan.h>
#include "Gateware.h"
#include <vector>
#include <fstream>
#include "h2bParser.h"
#include "FSLogo.h"
//model data for shader
#define MAX_SUBMESH_PER_DRAW 1024
struct SHADER_MODEL_DATA
{
	GW::MATH::GVECTORF sunDirection, sunColor, sunAmbi;
	GW::MATH::GMATRIXF view, projection;

	GW::MATH::GMATRIXF matricies[MAX_SUBMESH_PER_DRAW]; //world matrix
	OBJ_ATTRIBUTES materials[MAX_SUBMESH_PER_DRAW];
};
class Level
{
	//model i am storing data into
	std::vector<Model> myModel;
	std::vector<Model> LoadFile(const char* level, std::vector<Model> model)
	{
		Model tempModel; //thing to store temproary
		std::ifstream file;
		level = "GameLevel.txt"; //need to make robust to accomodate for both levels
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
				GetMatrix(level, buffer, &file, tempModel); //mating the matrix from txt file

			} while (!file.eof());

		}
		file.close();
	}
	GW::MATH::GMATRIXF GetMatrix(const char* level, char* buffer, std::ifstream *file, Model model)
	{
		// making the txt matrix into a float matrix
		Model tempModel = model; //thing to store
		GW::MATH::GMATRIXF modelMatrix; //matrix to store
		//loop through matrix
		for (int i = 0; i < 4; i++)
		{
			//row 1
			if (i = 0)
			{
				file->getline(buffer, 128, '('); // start of row matrix
				file->getline(buffer, 128, ','); // x of matrix
				tempModel.modelData.matricies[0].row1.x = atof(buffer);
				file->getline(buffer, 128, ','); // y  of matrix
				tempModel.modelData.matricies[0].row1.y= atof(buffer);
				file->getline(buffer, 128, ','); // z of matrix
				tempModel.modelData.matricies[0].row1.z = atof(buffer);
				file->getline(buffer, 128, ')'); // w and end of row matrix
				tempModel.modelData.matricies[0].row1.w = atof(buffer);
			}
			//row 2
			else if (i = 1)
			{
				file->getline(buffer, 128, '('); // start of row matrix
				file->getline(buffer, 128, ','); // x of matrix
				tempModel.modelData.matricies[0].row2.x = atof(buffer);
				file->getline(buffer, 128, ','); // y  of matrix
				tempModel.modelData.matricies[0].row2.y = atof(buffer);
				file->getline(buffer, 128, ','); // z of matrix
				tempModel.modelData.matricies[0].row2.z = atof(buffer);
				file->getline(buffer, 128, ')'); // w and end of row matrix
				tempModel.modelData.matricies[0].row2.w = atof(buffer);
			}
			//row 3
			else if (i = 2)
			{
				file->getline(buffer, 128, '('); // start of row matrix
				file->getline(buffer, 128, ','); // x of matrix
				tempModel.modelData.matricies[0].row3.x = atof(buffer);
				file->getline(buffer, 128, ','); // y  of matrix
				tempModel.modelData.matricies[0].row3.y = atof(buffer);
				file->getline(buffer, 128, ','); // z of matrix
				tempModel.modelData.matricies[0].row3.z = atof(buffer);
				file->getline(buffer, 128, ')'); // w and end of row matrix
				tempModel.modelData.matricies[0].row3.w = atof(buffer);
			}
			//row 4
			else
			{
				file->getline(buffer, 128, '('); // start of row matrix
				file->getline(buffer, 128, ','); // x of matrix
				tempModel.modelData.matricies[0].row4.x = atof(buffer);
				file->getline(buffer, 128, ','); // y  of matrix
				tempModel.modelData.matricies[0].row4.y = atof(buffer);
				file->getline(buffer, 128, ','); // z of matrix
				tempModel.modelData.matricies[0].row4.z = atof(buffer);
				file->getline(buffer, 128, ')'); // w and end of row matrix
				tempModel.modelData.matricies[0].row4.w = atof(buffer);
			}
			
		}
	}
};
class Model
{
public:
	VkBuffer vertexBuffer = nullptr;
	VkDeviceMemory vertexData = nullptr;
	VkBuffer indexBuffer = nullptr;
	VkDeviceMemory indexData = nullptr;
	H2B::Parser parse;
	SHADER_MODEL_DATA modelData;

	//this is where i will create a temporary
};