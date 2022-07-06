#pragma once
#include "objectHeaders/Camera.h"
#include "objectHeaders/Vector.h"
#include "objectHeaders/Settings.h"
#include "objectHeaders/Mesh.h"
#include "objectHeaders/Triangle.h"
#include "objectHeaders/Lights.h"
#include "objectHeaders/Color.h"
#include "rapidjson/istreamwrapper.h"
#include "rapidjson/document.h"
#include <iostream>
#include <assert.h>
#include <string.h>

class Scene {
public:
	Scene(const std::string& filename) {
		this->filename = filename;
	}
	void getCamera(Camera& cam);
	void getSettings(Settings& settings,Color& color);
	void getMeshes(Mesh& mesh);
	void getLights(Lights& lights);

private:
	std::string filename;
};
void Scene::getCamera(Camera& cam) {
	std::ifstream ifs(filename);
	assert(ifs.is_open());
	rapidjson::IStreamWrapper isw(ifs);
	rapidjson::Document doc;
	doc.ParseStream(isw);

	const rapidjson::Value& cameraVal = doc.FindMember("camera")->value;
	const rapidjson::Value& matrixVal = cameraVal.FindMember("matrix")->value;
	if (!cameraVal.IsNull() && cameraVal.IsObject())
	{
		assert(!matrixVal.IsNull() && matrixVal.IsArray());

		cam.setOrientation(Matrix(matrixVal[0].GetFloat(), matrixVal[1].GetFloat(), matrixVal[2].GetFloat(),
									  matrixVal[3].GetFloat(), matrixVal[4].GetFloat(), matrixVal[5].GetFloat(),
									  matrixVal[6].GetFloat(), matrixVal[7].GetFloat(), matrixVal[8].GetFloat()));
	}
	const rapidjson::Value& positionVal = cameraVal.FindMember("position")->value;
	if (!cameraVal.IsNull() && cameraVal.IsObject())
	{
		assert(!positionVal.IsNull() && positionVal.IsArray());
		cam.setPosition(Vector(positionVal[0].GetFloat(),
			positionVal[1].GetFloat(),
			positionVal[2].GetFloat()));
	}
}
void Scene::getSettings(Settings& settings,Color& color) {
	std::ifstream ifs(filename);
	assert(ifs.is_open());
	rapidjson::IStreamWrapper isw(ifs);
	rapidjson::Document doc;
	doc.ParseStream(isw);

	const rapidjson::Value& settingsVal = doc.FindMember("settings")->value;
	const rapidjson::Value& imgSettingsVal = settingsVal.FindMember("image_settings")->value;
	if (!settingsVal.IsNull() && settingsVal.IsObject()) {
		const rapidjson::Value& imgWidthVal = imgSettingsVal.FindMember("width")->value;
		const rapidjson::Value& imgHeightVal = imgSettingsVal.FindMember("height")->value;
		assert(!imgWidthVal.IsNull() && imgWidthVal.IsInt() && !imgHeightVal.IsNull() && imgHeightVal.IsInt());
		settings.setImageHeight(imgHeightVal.GetInt());
		settings.setImageWidth(imgWidthVal.GetInt());
	}
	const rapidjson::Value& bgColor = settingsVal.FindMember("background_color")->value;
	if (!bgColor.IsNull() && bgColor.IsObject()) {
		assert(!bgColor.IsNull() && bgColor.IsArray());

	}
}

void Scene::getMeshes(Mesh& mesh){
	std::ifstream ifs(filename);
	assert(ifs.is_open());
	rapidjson::IStreamWrapper isw(ifs);
	rapidjson::Document doc;
	doc.ParseStream(isw);

	const rapidjson::Value& objectVal = doc.FindMember("objects")->value;
	if (!objectVal.IsNull() && !objectVal.IsObject()) {
		//how many objects have
		mesh.setObject(objectVal.Size());
		for (int i = 0; i < objectVal.Size(); i++) {
			const rapidjson::Value& verticesVal = objectVal[i].FindMember("vertices")->value;
			assert(!verticesVal.IsNull() && verticesVal.IsArray());
			for (int i = 0; i < verticesVal.Size() / 3; i++) {
				Vector vertices;
				vertices.x = verticesVal[3 * i].GetFloat();
				vertices.y = verticesVal[3 * i + 1].GetFloat();
				vertices.z = verticesVal[3 * i + 2].GetFloat();
				
				mesh.setVertecs(vertices);
				
			}
			const rapidjson::Value& trianglesVal = objectVal[i].FindMember("triangles")->value;
			assert(!trianglesVal.IsNull() && trianglesVal.IsArray());
			for (int j = 0; j < trianglesVal.Size() / 3; j++) {
				
				Triangle triangle(mesh.getVertecs(trianglesVal[3 * j].GetInt()),
								  mesh.getVertecs(trianglesVal[3 * j + 1].GetInt()),
								  mesh.getVertecs(trianglesVal[3 * j + 2].GetInt()));

				mesh.setTriangles(triangle);
				
			}
			mesh.clearVertecs();
		}
	}
}
void Scene::getLights(Lights& lights) {
	std::ifstream ifs(filename);
	assert(ifs.is_open());
	rapidjson::IStreamWrapper isw(ifs);
	rapidjson::Document doc;
	doc.ParseStream(isw);

	const rapidjson::Value& lightsVal = doc.FindMember("lights")->value;
	if (!lightsVal.IsNull() && !lightsVal.IsObject()) {
		for (int i = 0; i < lightsVal.Size(); i++) {
			const rapidjson::Value& positionVal = lightsVal[i].FindMember("position")->value;
			assert(!positionVal.IsNull() && positionVal.IsArray());
			Vector position = Vector(positionVal[0].GetFloat(), positionVal[1].GetFloat(), positionVal[2].GetFloat());
			lights.setPosition(position);
			const rapidjson::Value& intensityVal = lightsVal[i].FindMember("intensity")->value;
			//assert(!intensityVal.IsNull() && intensityVal.IsArray());
			lights.setIntensity(intensityVal.GetFloat());
		}

	}
}