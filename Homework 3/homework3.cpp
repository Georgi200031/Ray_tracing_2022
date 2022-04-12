#include <fstream>
#include <vector>
#include <cmath>
#define crtTab "\t"
#define crtNewLine "\n" 

static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;
static const int maxRandColors = 255;

std::ofstream ppmFileStream("homework3.ppm", std::ios::out | std::ios::binary);

struct vec_origin
{
	public :
		double x,y,z;
}rayDir;

class create_camera_rays
{
	public:
		void find_center()
			{
				rayDir.x = rayDir.x + 0.5;
                                rayDir.y = rayDir.y + 0.5;
			}
		void convert_raster_to_NDC()
			{
				rayDir.x = rayDir.x / imageWidth;
                                rayDir.y = rayDir.y / imageHeight;
			}
		void convert_NDC_to_screen()
			{
				rayDir.x = ((2.0 * rayDir.x)-1.0);
				rayDir.y = -1*(1.0 - (2.0 * rayDir.y));
			}			
		void aspect_ratio()
			{
				rayDir.x = rayDir.x * (imageWidth/imageHeight);
			}
		void normalaize_ray()
			{
				double Length = sqrt(pow(rayDir.x,2) + pow(rayDir.y,2));
				rayDir.x = rayDir.x / abs(Length);	
				rayDir.y = rayDir.y / abs(Length); 
			}
};

int main()
{
	create_camera_rays ray;	
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";	
	for(int rowIdx = 0 ; rowIdx < imageHeight ; rowIdx++)
	{	
		for(int colIdx=0; colIdx < imageWidth; colIdx++)
		{
				
				rayDir.x = rowIdx;
				rayDir.y = colIdx;
				ray.find_center();
				ray.convert_raster_to_NDC();
				ray.convert_NDC_to_screen();
				ray.aspect_ratio();
				ray.normalaize_ray();
				
				ppmFileStream << (int)(((rayDir.x + 1) / 2.0) * 255) << " ";
            			ppmFileStream << (int)(((rayDir.y + 1) / 2.0) * 255) << " ";
            			ppmFileStream << 0 << "\t";		
		
		}	
		ppmFileStream << crtNewLine;
	}
	ppmFileStream.close();
	return 0;
}
