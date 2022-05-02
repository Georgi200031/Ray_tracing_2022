#ifndef SCENE_H
#define SCENE_H
#include <vector>


#include "settings.h"
#include "Headers/vector.h"
//#include "Headers/object.h"
#include "Headers/matrix.h"
#include "rapidjson/istreamwrapper.h"
#include"rapidjson/document.h"

class Scene
{
	public:
		int imageWidth;
		int imageHeight;
		double r,g,b;
		int Objects;
		int index;
		std::vector<double> lengthObject;
		std::vector<int> tri;
		double Object[0][0];
		
		double camPosX,camPosY,camPosZ;
		Matrix rotMat;
		Scene();
		
		
		void getCamera(const std::string& filename);	
		void getResolution(const std::string& filename);
		void getBackgroundColor(const std::string& filename);
		void getObjects(const std::string& filename);
		
};

Scene::Scene()
{
	imageWidth = 0;
	imageHeight = 0;
	r = 0;
	g = 0;
	b = 0;
	Objects = 0; 
	//lengthObject[0] = 0;
}

void Scene::getCamera(const std::string& filename)
{       
        std::ifstream ifs(filename);
        assert(ifs.is_open());
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        
        const rapidjson::Value& cameraVal = doc.FindMember("camera")->value;
        const rapidjson::Value& matrixVal = cameraVal.FindMember("matrix")->value;
        if(!cameraVal.IsNull() && cameraVal.IsObject())
        {       
		assert(!matrixVal.IsNull() && matrixVal.IsArray());
			rotMat = Matrix(matrixVal[0].GetDouble(),matrixVal[1].GetDouble(),matrixVal[2].GetDouble(),
					matrixVal[3].GetDouble(),matrixVal[4].GetDouble(),matrixVal[5].GetDouble(),
					matrixVal[6].GetDouble(),matrixVal[7].GetDouble(),matrixVal[8].GetDouble());
        }
	const rapidjson::Value& positionVal = cameraVal.FindMember("position")->value;
	if(!cameraVal.IsNull() && cameraVal.IsObject())
	{
		assert(!positionVal.IsNull() && positionVal.IsArray());
		camPosX = positionVal[0].GetDouble();
		camPosY = positionVal[1].GetDouble();
		camPosZ = positionVal[2].GetDouble();
	}
        
}       


void Scene::getResolution(const std::string& filename) 
{
	std::ifstream ifs(filename);
        assert(ifs.is_open());
        rapidjson::IStreamWrapper isw(ifs);
	rapidjson::Document doc;
        doc.ParseStream(isw);

	const rapidjson::Value& settingsVal = doc.FindMember("settings")->value;
	const rapidjson::Value& imgSettingsVal = settingsVal.FindMember("image_settings")->value;
	if(!settingsVal.IsNull() && settingsVal.IsObject())
	{
      		const rapidjson::Value& imgWidthVal = imgSettingsVal.FindMember("width")->value;
      		const rapidjson::Value& imgHeightVal = imgSettingsVal.FindMember("height")->value;
       		assert(!imgWidthVal.IsNull() && imgWidthVal.IsInt() && !imgHeightVal.IsNull() && imgHeightVal.IsInt());
      		imageWidth = imgWidthVal.GetInt();
		imageHeight = imgHeightVal.GetInt();
	}
	
}
void Scene::getBackgroundColor(const std::string& filename)
{
	std::ifstream ifs(filename);
        assert(ifs.is_open());
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);
        
        const rapidjson::Value& settingsVal = doc.FindMember("settings")->value;
        if(!settingsVal.IsNull() && settingsVal.IsObject())
        {
		const rapidjson::Value& bgColor = settingsVal.FindMember("background_color")->value;
		assert(!bgColor.IsNull() && bgColor.IsArray());
		r = bgColor[0].GetDouble();
		g = bgColor[1].GetDouble();
		b = bgColor[2].GetDouble();
		
        }       

}
 void Scene::getObjects(const std::string& filename)
 {       
 	std::ifstream ifs(filename);
        assert(ifs.is_open());
        rapidjson::IStreamWrapper isw(ifs);
        rapidjson::Document doc;
        doc.ParseStream(isw);

        const rapidjson::Value& objectVal = doc.FindMember("objects")->value;
        Objects = objectVal.Size();

	if(!objectVal.IsNull() && !objectVal.IsObject())
        {
	
		for (int i = 0; i <objectVal.Size(); i++) 
		{		
			const rapidjson::Value& verticesVal = objectVal[i].FindMember("vertices")->value;
			
			assert(!verticesVal.IsNull() && verticesVal.IsArray());
			lengthObject.push_back( verticesVal.Size());
			for (int j = 0; j < verticesVal.Size(); j++) 
			{	
				Object[i][index] = verticesVal[j].GetDouble();
				index++;
    			}
			index = 0; 
						
        		
        		const rapidjson::Value& trianglesVal = objectVal[i].FindMember("triangles")->value;
        		
			assert(!trianglesVal.IsNull() && trianglesVal.IsArray());
        		for (int j = 0; j < trianglesVal.Size(); j++)
                        {
                               	tri.push_back(trianglesVal[j].GetInt());
                        }
			
		}
	}
}


#endif
