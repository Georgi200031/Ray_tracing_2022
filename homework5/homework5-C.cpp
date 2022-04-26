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

std::ofstream ppmFileStream("homework5-C.ppm", std::ios::out | std::ios::binary);

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
	
	//color all triangle
	Triangle triangleOne = Triangle(Vector(-0.5,0,-3), Vector(0.5,0,-3), Vector(0,1,-3));
	Triangle triangleTwo = Triangle(Vector(-0.5,-1, -3), Vector(-0.5, 0, -3), Vector(-1.5,0, -3));
	Triangle triangleThree = Triangle(Vector(0.5,0, -3), Vector(0.5, -1, -3), Vector(1.5,0, -3));	
	Triangle triangleFour = Triangle(Vector(0.5,-1,-3), Vector(-0.5, -1, -3), Vector(0,-2, -3));
		
	//color quadrat
	Triangle triangleFive = Triangle(Vector(-0.5, -1, -3), Vector(0.5,0,-3) , Vector(-0.5,0,-3));
	Triangle triangleSix = Triangle(Vector(0.5, 0, -3), Vector(-0.5,-1,-3) , Vector(0.5,-1,-3));
	
	double rpDist = MOD((triangleOne.vert[0]).dot(triangleOne.normal()));
	
	//double rpDist = MOD((triangleTwo.vert[0]).dot(triangleTwo.normal()));
	
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";	
	for(int rowIdx = 0 ; rowIdx < imageHeight ; rowIdx++)
	{	
		for(int colIdx=0; colIdx < imageWidth; colIdx++)
		{
				Vector ray = Vector(colIdx, rowIdx, -1.0);
				ray.find_center();
				ray.convert_raster_to_NDC();
				ray.convert_NDC_to_screen();
				ray.aspect_ratio();
				ray.normalize();
				
				double rProj = MOD(ray.dot(triangleOne.normal()));
				double t = rpDist/rProj;
				Vector p = Vector(origin.operator+(ray.operator*(t)));
				
					
				
				if (triangleOne.normal().dot(ray)!=0 && (triangleOne.vert[0]).dot(triangleOne.normal()) < 0 || 
			    	    triangleTwo.normal().dot(ray)!=0 && (triangleTwo.vert[0]).dot(triangleTwo.normal()) < 0 ||
				    triangleThree.normal().dot(ray)!=0 && (triangleThree.vert[0]).dot(triangleThree.normal()) < 0 ||
				    triangleFour.normal().dot(ray)!=0 && (triangleFour.vert[0]).dot(triangleFour.normal()) < 0 ||
				    triangleFive.normal().dot(ray)!=0 && (triangleFive.vert[0]).dot(triangleFive.normal()) < 0 ||
				    triangleFive.normal().dot(ray)!=0 && (triangleFive.vert[0]).dot(triangleFive.normal()) < 0) 
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
							else if((triangleThree.normal()).dot(triangleThree.E0().cross(triangleThree.V0P(p))) > 0
                                                             && (triangleThree.normal()).dot(triangleThree.E1().cross(triangleThree.V1P(p))) > 0
                                                             && (triangleThree.normal()).dot(triangleThree.E2().cross(triangleThree.V2P(p))) > 0)
                                                                {
                                                                        ppmFileStream << 0 << " " << 255 << " " << 0 << crtTab;
                                                                }
							else if((triangleFour.normal()).dot(triangleFour.E0().cross(triangleFour.V0P(p))) > 0
                                                             && (triangleFour.normal()).dot(triangleFour.E1().cross(triangleFour.V1P(p))) > 0
                                                             && (triangleFour.normal()).dot(triangleFour.E2().cross(triangleFour.V2P(p))) > 0)
                                                                {
                                                                        ppmFileStream << 0 << " " << 255 << " " << 0 << crtTab;
                                                                }
							else if((triangleFive.normal()).dot(triangleFive.E0().cross(triangleFive.V0P(p))) > 0
                                                             && (triangleFive.normal()).dot(triangleFive.E1().cross(triangleFive.V1P(p))) > 0
                                                             && (triangleFive.normal()).dot(triangleFive.E2().cross(triangleFive.V2P(p))) > 0)
                                                                {
                                                                        ppmFileStream << 255 << " " << 0 << " " << 0 << crtTab;
                                                                }
							 else if((triangleSix.normal()).dot(triangleSix.E0().cross(triangleSix.V0P(p))) > 0
                                                             && (triangleSix.normal()).dot(triangleSix.E1().cross(triangleSix.V1P(p))) > 0
                                                             && (triangleSix.normal()).dot(triangleSix.E2().cross(triangleSix.V2P(p))) > 0)
                                                                {
                                                                        ppmFileStream << 255 << " " << 0 << " " << 0 << crtTab;
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

