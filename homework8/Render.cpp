/*
        Creator: Georgi Valeriev Rusev
        Program: Render whitch use json file with triangles and redering.
*/
#include <iostream>
#include <fstream>
#include "objectHeaders/Ray.h"
#include "objectHeaders/Vector.h"
#include "objectHeaders/Triangle.h"
#include "objectHeaders/Render.h"
#include "objectHeaders/Camera.h"
#include "objectHeaders/Settings.h"
#include "objectHeaders/Mesh.h"
#include "objectHeaders/Lights.h"
#include "Scene.h"

#define crtTab "\t"
#define crtNewLine "\n" 
// full Hd
static const int imageWidth = 1920;
static const int imageHeight = 1080;



std::ofstream ppmFileStream("output/scene0.ppm", std::ios::out | std::ios::binary);



int main()
{
	Camera cam;
	Settings settings;
	Color color;
	Mesh mesh;
	Lights lights;
	Scene sceneOne("input/scene0.crtscene");
	sceneOne.getCamera(cam);
	sceneOne.getSettings(settings,color);
	sceneOne.getLights(lights);

	

	//create triangle
	bool check = false;
	sceneOne.getMeshes(mesh);
	
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";


	for (int rowIdx = 0; rowIdx < imageHeight; ++rowIdx) {
		for (int colIdx = 0; colIdx < imageWidth; ++colIdx) {

			//In ray store new direction vector & ray.getDirection(); get it
			Ray ray = createRay(colIdx, rowIdx,imageWidth, imageHeight, cam);
			Vector normalTriangleInter;
			Vector hitPoint;
			int indexOfTriangle = 0; 
			for (int i = 0; i < mesh.size(); i++) {
			
				if (findIntersection(ray, mesh.getTriangle(i),cam) == true) {
					check = true;
					hitPoint = ray.getHitPoint();
					normalTriangleInter = mesh.getTriangle(i).getNormal();
					indexOfTriangle = i;
					break;
				}
			} 
		
			if (check == true) {
			    color = shading(hitPoint, normalTriangleInter, settings, lights, cam, mesh,indexOfTriangle);
				
				ppmFileStream << (int)color.getR() << " " << (int)color.getG() << " " << (int)color.getB() << crtTab;
			}
			else {
				ppmFileStream << 0 << " " << 250*0.5 << " " << 0 << crtTab;
			}
			check = false;
		}
		ppmFileStream << crtNewLine;
	}    
	ppmFileStream.close();
	return 0;
}