#include <fstream> 
#include <vector>
#include <cmath>
#include <string>

#include "triangle.h"
#include "vector.h"
#include "matrix.h"
#include "camera.h"

#define crtTab "\t"
#define crtNewLine "\n" 


static const int maxColorComponent = 255;
//static const int maxRandColors = 255;

//std::ofstream ppmFileStream("homework6-C-origin-dolly.ppm", std::ios::out | std::ios::binary);

double MOD(double x)
{
	double result = x;
	if(result<0)
		result = -1 * result; 
	return result;
}	

int main()
{	
	int degree = 0;
	Triangle triangleOne = Triangle(Vector(-1.75,-1.75,-3),Vector(1.75,-1.75,-3),Vector(0,1.75,-3));
	for(int frame = 0; frame < 72;frame++)
	{	
		degree = degree + 5;	
		std::ofstream ppmFileStream(std::to_string(frame)+".ppm", std::ios::out | std::ios::binary);
		ppmFileStream << "P3\n";
		ppmFileStream << imageWidth << " " << imageHeight << "\n";
		ppmFileStream << maxColorComponent << "\n";	
		for(int rowIdx = 0 ; rowIdx < imageHeight ; rowIdx++)
			{	
				for(int colIdx=0; colIdx < imageWidth; colIdx++)
					{
						Camera camera;
						camera.Ray = Vector(colIdx,rowIdx,-1.0);				
						camera.Ray.find_center();
						camera.Ray.convert_raster_to_NDC();
						camera.Ray.convert_NDC_to_screen();
						camera.Ray.aspect_ratio();
						camera.dolly(1);
	
						//camera.truck(1);
						//camera.pedestal(1);
						camera.pan(degree);
						//camera.tilt(30);
						//camera.roll(30);
						//camera.pan(30);
						//camera.truck(-2);
						//camera.tilt(-30);
						//camera.roll(30);
								
						camera.Ray.normalize();
						camera.Pos = Vector(0,0,1);
						camera.Origin = camera.Pos;

						double rpDist = MOD(((triangleOne.vert[0]).operator-(camera.Pos)).dot(triangleOne.normal()));
						double rProj = MOD(camera.Ray.dot(triangleOne.normal()));
						double t = rpDist/rProj;
						Vector p = Vector(camera.Origin.operator+(camera.Ray.operator*(t)));	
			
				
						if (triangleOne.normal().dot(camera.Ray)!=0 && (triangleOne.vert[0]).dot(triangleOne.normal()) < 0) 
							{
					
								if((triangleOne.normal()).dot(triangleOne.E0().cross(triangleOne.V0P(p))) > 0 
								&& (triangleOne.normal()).dot(triangleOne.E1().cross(triangleOne.V1P(p))) > 0 
								&& (triangleOne.normal()).dot(triangleOne.E2().cross(triangleOne.V2P(p))) > 0)
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
		}
	//ppmFileStream.close();
	return 0;
}

