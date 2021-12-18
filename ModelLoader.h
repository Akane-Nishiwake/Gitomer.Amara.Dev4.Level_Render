#pragma once
#include <vulkan/vulkan.h>
//#include "Gateware.h"
//#include <vector>
#include <fstream>
#include "h2bParser.h"
#include "FSLogo.h"
//#include "../OBJ/DoorSingle_Wall_SideB.h"
//model data for shader
#define MAX_SUBMESH_PER_DRAW 1024
struct SHADER_MODEL_DATA
{
	GW::MATH::GVECTORF sunDirection, sunColor , Ambi, camWpos;
	GW::MATH::GMATRIXF view, projection;

	GW::MATH::GMATRIXF matricies[MAX_SUBMESH_PER_DRAW]; //world matrix
	OBJ_ATTRIBUTES materials[MAX_SUBMESH_PER_DRAW];

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
	std::string modelName;

	Model()
	{
		vertexBuffer = nullptr;
		vertexData = nullptr;
		indexBuffer = nullptr;
		indexData = nullptr;
		
	}
	~Model() = default;
	Model(const Model& copy) = default;

	//model i am storing data into
	void LoadFile(const char* h2bFile)
	{
		//parse.Parse(h2bFile);
		bool b = parse.Parse(h2bFile);
		float debug = 0;
	}

	
};
class Level
{
public:
	std::ifstream file;
	std::vector <Model> myModel;
	void LoadLevel(const char* level)
	{
		file.open(level, std::ios_base::in);
		if (file.is_open())
		{
			char buffer[128];
			file.getline(buffer, 128); //header
			do {
				file.getline(buffer, 128, '\n'); //type
				if (strcmp(buffer, "MESH") == 0)
				{
					Model temp;
					file.getline(buffer, 128, '\n'); // name
					std::string name = "../OBJ/";
					temp.modelName = std::string(buffer);
					name.append(temp.modelName);
					name.append(".h2b");
					char* sally = const_cast <char*> (name.c_str()); // making sally the .h2b
					temp.LoadFile(sally); //parsing the .h2b
					GetMatrix(level, temp);	//matrix
					myModel.push_back(temp); //<- this is where i am pushing data
					float debug = 0;

				}

			} while (!file.eof());

		}
		file.close();
	}
	// This goes in Level class
	void GetMatrix(const char* level,  Model &model)
	{
		char buffer[128];
		// making the txt matrix into a float matrix
		/*Model &tempModel = model;*/ //thing to store
		//loop through matrix
		for (int i = 0; i < 4; i++)
		{
			//row 1
			if (i == 0)
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				model.modelData.matricies[0].row1.x = atof(buffer); //asciiz to float adding it to the model data
				file.getline(buffer, 128, ','); // y  of matrix
				model.modelData.matricies[0].row1.y = atof(buffer);
				file.getline(buffer, 128, ','); // z of matrix
				model.modelData.matricies[0].row1.z = atof(buffer);
				file.getline(buffer, 128, ')'); // w and end of row matrix
				model.modelData.matricies[0].row1.w = atof(buffer);
			}
			//row 2
			else if (i == 1)
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				model.modelData.matricies[0].row2.x = atof(buffer);
				file.getline(buffer, 128, ','); // y  of matrix
				model.modelData.matricies[0].row2.y = atof(buffer);
				file.getline(buffer, 128, ','); // z of matrix
				model.modelData.matricies[0].row2.z = atof(buffer);
				file.getline(buffer, 128, ')'); // w and end of row matrix
				model.modelData.matricies[0].row2.w = atof(buffer);
			}
			//row 3
			else if (i == 2)
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				model.modelData.matricies[0].row3.x = atof(buffer);
				file.getline(buffer, 128, ','); // y  of matrix
				model.modelData.matricies[0].row3.y = atof(buffer);
				file.getline(buffer, 128, ','); // z of matrix
				model.modelData.matricies[0].row3.z = atof(buffer);
				file.getline(buffer, 128, ')'); // w and end of row matrix
				model.modelData.matricies[0].row3.w = atof(buffer);
			}
			//row 4
			else
			{
				file.getline(buffer, 128, '('); // start of row matrix
				file.getline(buffer, 128, ','); // x of matrix
				model.modelData.matricies[0].row4.x = atof(buffer);
				file.getline(buffer, 128, ','); // y  of matrix
				model.modelData.matricies[0].row4.y = atof(buffer);
				file.getline(buffer, 128, ','); // z of matrix
				model.modelData.matricies[0].row4.z = atof(buffer);
				file.getline(buffer, 128, ')'); // w and end of row matrix
				model.modelData.matricies[0].row4.w = atof(buffer);
			}

		}
	}
};
