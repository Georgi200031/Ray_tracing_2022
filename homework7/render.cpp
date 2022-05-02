#include <fstream> 
#include <vector>
#include <cmath>
#include <cstdlib>

#include "scene.h"
#include "Headers/triangle.h"
#include "Headers/vector.h"
#include "Headers/matrix.h"
#include "Headers/camera.h"

#define crtTab "\t"
#define crtNewLine "\n" 


static const int maxColorComponent = 255;
//static const int maxRandColors = 255;

std::ofstream ppmFileStream("pictures/scene0.ppm", std::ios::out | std::ios::binary);

double MOD(double x)
{
	double result = x;
	if(result<0)
		result = -1 * result; 
	return result;
}	

int main()
{		
	Scene sceneOne;
	sceneOne.getResolution("scene0.crtscene");
	sceneOne.getBackgroundColor("scene0.crtscene");
	sceneOne.getObjects("scene0.crtscene");	
	std::vector<Vector> vertecs;
	for(int i = 0; i < sceneOne.Objects; i++)
		{
			for(int j = 1; j <= sceneOne.lengthObject[i]/3; j++)
			{
				vertecs.emplace_back(sceneOne.Object[i][3*j-3],
					          sceneOne.Object[i][3*j+1-3],
						  sceneOne.Object[i][3*j+2-3]);
			}
		}		
	sceneOne.getCamera("scene0.crtscene");  
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
                                
				//camera.dolly(1);        
                                //camera.truck(1);
                                //camera.pedestal(1);
                                //camera.pan(30);
                                //camera.tilt(30);
                                //camera.roll(30);
                                //camera.pan(30);
                                //camera.truck(-2);
                                //camera.tilt(-30);
                                //camera.roll(30);
				
				camera.orientation(sceneOne.rotMat);
                                camera.Ray.normalize();
                                camera.Pos = Vector(sceneOne.camPosX,sceneOne.camPosY,sceneOne.camPosZ);
			
				for(int i = 0;i< sceneOne.Objects;i++ )
                                        for(int j=0;j< triangle.tri.size()/3;j++)
                                        {
			
                                        Triangle triangleOne=Triangle(vertecs[sceneOne.tri[3*j]],vertecs[sceneOne.tri[3*j+1]],vertecs[sceneOne.tri[3*j+2]]);
                             		
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
								//	ppmFileStream <<sceneOne.r<<" "<<sceneOne.g<<" "<<sceneOne.b <<crtTab;
									ppmFileStream << 0 << " " << 255 << " " << 0 << crtTab;
								}
							else
								{
									//ppmFileStream <<sceneOne.r<<" "<<sceneOne.g<<" "<<sceneOne.b <<crtTab;
									ppmFileStream << 250 << " " << 250 << " " << 250 << crtTab; 
								}
					}
					else
					{
						ppmFileStream << 250 << " " << 250 << " " << 250 << crtTab;
						// ppmFileStream <<sceneOne.r<<" "<<sceneOne.g<<" "<<sceneOne.b <<crtTab;
					}
					
				}
					
		}	

		ppmFileStream << crtNewLine;
	}
	ppmFileStream.close();
	return 0;
}
