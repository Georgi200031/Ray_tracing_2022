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

std::ofstream ppmFileStream("homework5-B.ppm", std::ios::out | std::ios::binary);

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
	
	Triangle triangleOne = Triangle(Vector(-1.75,-1.75,-3),Vector(1.75,-1.75,-3),Vector(0,1.75,-3));
	Triangle triangleTwo = Triangle(Vector(1.75, -1.75, -3), Vector(3, -2, -3), Vector(2,2, -3));
	
	double rpDist = MOD((triangleOne.vert[0]).dot(triangleOne.normal()));
	
	//double rpDist = MOD((triangleTwo.vert[0]).dot(triangleTwo.normal()));
	
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
				
				double rProj = MOD(ray.dot(triangleOne.normal()));
				double t = rpDist/rProj;
				Vector p = Vector(origin.operator+(ray.operator*(t)));
				
					
				
				if (triangleOne.normal().dot(ray)!=0 && (triangleOne.vert[0]).dot(triangleOne.normal()) < 0 || 
			            triangleTwo.normal().dot(ray)!=0 && (triangleTwo.vert[0]).dot(triangleTwo.normal())) 
					{
					
							if((triangleOne.normal()).dot(triangleOne.E0().cross(triangleOne.V0P(p))) > 0 
							&& (triangleOne.normal()).dot(triangleOne.E1().cross(triangleOne.V1P(p))) > 0 
							&& (triangleOne.normal()).dot(triangleOne.E2().cross(triangleOne.V2P(p))) > 0)
								{
									ppmFileStream << 0 << " " << 255 << " " << 0 << crtTab;
								}
							else if((triangleTwo.normal()).dot(triangleTwo.E0().cross(triangleTwo.V0P(p))) > 0
                                                             && (triangleTwo.normal()).dot(triangleTwo.E1().cross(triangleTwo.V1P(p))) > 0
                                                             && (triangleTwo.normal()).dot(triangleTwo.E2().cross(triangleTwo.V2P(p))) > 0)
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
