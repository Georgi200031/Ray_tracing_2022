#include <fstream>
#include <vector>
#include <cmath>
#include "triangle.h"
#include "vector.h"
#include <vector>
#define crtTab "\t"
#define crtNewLine "\n" 


static const int maxColorComponent = 255;
static const int maxRandColors = 255;

std::ofstream ppmFileStream("homework5-A.ppm", std::ios::out | std::ios::binary);

double MOD(double x)
{
	double result = x;
	if(result<0)
		result = -1 * result; 
	return result;
}	

int main()
{
	Vector origin = Vector(0,0,0);

	Vector vertOne = Vector(-1.75,-1.75,-3);
	Vector vertTwo = Vector(1.75,-1.75,-3);
	Vector vertThree = Vector(0,1.75,-3);
	
	Triangle triangleOne = Triangle(Vector(-1.75,-1.75,-3),Vector(1.75,-1.75,-3),Vector(0,1.75,-3));
	
	//find normal vector of triangleOne
	//->	
	Vector E0 = Vector(triangleOne.vert[1].operator-(triangleOne.vert[0]));
	Vector E1 = Vector(triangleOne.vert[2].operator-(triangleOne.vert[1]));
	Vector E2 = Vector(triangleOne.vert[0].operator-(triangleOne.vert[2]));	

	E0.print();
	E1.print();
	
	Vector triangleNormal = Vector(E0.cross(E1));
	triangleNormal.normalize();
	triangleNormal.MOD();
        triangleNormal.print();
	//<-
	
	double rpDist = MOD(vertOne.dot(triangleNormal));
	
	
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
				ray.normalize();
				
				double rProj = MOD(ray.dot(triangleNormal));
				double t = rpDist/rProj;
				Vector p = Vector(origin.operator+(ray.operator*(t)));
				Vector VOP = Vector(p.operator-(triangleOne.vert[0]));
				Vector V1P = Vector(p.operator-(triangleOne.vert[1]));
				Vector V2P = Vector(p.operator-(triangleOne.vert[2]));
				
					
				if (triangleNormal.dot(ray)!=0 && vertOne.dot(triangleNormal) < 0) 
					{
					
							if(triangleNormal.dot(E0.cross(VOP))> 0 && triangleNormal.dot(E1.cross(V1P)) > 0 && triangleNormal.dot(E2.cross(V2P)) > 0)
								{
									ppmFileStream << 0 << " " << 255 << " " << 0 << crtTab;
								}
                					else
								{
									ppmFileStream << 250 << " " << 250 << " " << 250 << crtTab;
								}
					}
				else 
					{
						 ppmFileStream << 250 << " " << 250 << " " << 250 << crtTab;
					}
		}	

		ppmFileStream << crtNewLine;
	}
	ppmFileStream.close();
	return 0;
}

