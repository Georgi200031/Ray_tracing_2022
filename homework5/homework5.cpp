#include <fstream>
#include <vector>
#include <cmath>
#include <iostream>
#include "vector.h"
#define crtTab "\t"
#define crtNewLine "\n" 

//static const int imageWidth = 1920;
//static const int imageHeight = 1080;

static const int vertsInTriangle = 4;
#include <vector>
static const int maxColorComponent = 255;
static const int maxRandColors = 255;

std::ofstream ppmFileStream("homework5.ppm", std::ios::out | std::ios::binary);

class K
{
	public:   	
		double x,y,z;	
		K();
	        K(double x,double y,double z);
		//Triangle(const Vector& vertOne, const Vector& vertTwo, const Vector& vertThree);
		//Vector normal() const { return this->n; }

	private:
        	Vector vert[vertsInTriangle];
		Vector n;
     
};

K::K(double x,double y,double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

//Triangle::Triangle(const Vector& vertOne, const Vector& vertTwo, const Vector& vertThree);
int main()
{

	K triangleOne = K(1,2,3); 

	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";	
	for(int rowIdx = 0 ; rowIdx < imageHeight ; rowIdx++)
	{	
		for(int colIdx=0; colIdx < imageWidth; colIdx++)
		{
				Vector ray = Vector(rowIdx, colIdx, -1.0);
				ray.find_center();
				ray.convert_raster_to_NDC();
				ray.convert_NDC_to_screen();
				ray.aspect_ratio();
				ray.normalaize_ray();
			//	const int intersectedTRiangle = triangleInteresection(ray, triangles);
			//	if (intersectedTriangle != -1)
			//		{
			//			ppmFileStream << 0 << " " << 255 << " " << 0 << crtTab;
			//		}
			//	else 
			//	{
			//		ppmFileStream << 255 << " " << 255 << " " << 255 << crtTab;
			//	}
		}	
		ppmFileStream << crtNewLine;
	}
	ppmFileStream.close();
	return 0;
}

