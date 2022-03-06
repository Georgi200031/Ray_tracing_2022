#include <fstream> 


static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;

static const int rectangle_a = 4;
static const int rectangle_b = 4;
static const int triangle_h = 1;

struct house{
	int x;
	int y;
}start_triangle,start_window,start_door,start_rectangle,center;


void create_point()
{	
	center.x = imageWidth/2;
	center.y = imageHeight/2;
	start_triangle.x = 1;
	start_triangle.y = center.y - rectangle_b*100/2;
	start_door.x = center.y + center.y*0.1;
	start_door.y = center.x + center.x*0.05;
	start_window.x = start_triangle.y + start_triangle.y/4; 
	start_window.y = start_window.x*0.4 +start_window.x;
	start_rectangle.y = center.y + rectangle_b*100/2;
}
std::ofstream ppmFileStream("house.ppm", std::ios::out | std::ios::binary);

class build_house
	{
		public :
			void build_walls()
			{
				ppmFileStream << 30 << " " << 255 << " " << 0 <<"\t";
			}
		public :
                        void build_roof()
                        {
                                ppmFileStream << 255 << " " << 0 << " " << 4 <<"\t";
                        }
		public :
                        void build_door()
                        {
                                ppmFileStream << 0 << " " << 0 << " " << 0 <<"\t";
                        }
		public :
                        void build_window()
                        {
                                ppmFileStream << 242 << " " << 255 << " " << 4 <<"\t";
                        }	
	};
int main()
{
	create_point();
	int left = center.x;
	int right = center.x;
	build_house house1;
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";	
	for(int rowldx = 0 ; rowldx < imageHeight ; rowldx++)
	{	
		for(int colldx=0; colldx < imageWidth; colldx++)
		{

			if(start_triangle.x<=rowldx && start_triangle.y>rowldx && left <= colldx && right >= colldx)
				house1.build_roof();
			else if(start_window.x <= rowldx && start_window.y>=rowldx  && (left + left*0.1) <= colldx && (left + left*0.2 + left*0.3)  >= colldx)
				house1.build_window();
			else if(start_door.x <= rowldx && start_rectangle.y>=rowldx  && start_door.y+start_door.y*0.1 <= colldx && start_door.y+start_door.y*0.25 >= colldx)
				house1.build_door();
			else if(start_triangle.y <= rowldx && start_rectangle.y>=rowldx  && left <= colldx && right >= colldx)
                                house1.build_walls();	
			else if(600<=rowldx)
				ppmFileStream << 169 << " " << " " << 169 << " " << 169 << "\t";
			else
				ppmFileStream << 169 << " " << " " << 169 << " " << 169 << "\t";
		}	
		if(rowldx<start_triangle.y)
			{
				left = left - 1;
                		right = right + 1;
			}
		ppmFileStream << "\n";
	}
	ppmFileStream.close();
	return 0;
}
