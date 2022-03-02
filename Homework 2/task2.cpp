#include <fstream> 

static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;

static const int rectangle_a = 5;
static const int rectangle_b = 3;

static bool fill=0;

struct rectangle{
	int x;
	int y;
}p1,p2,center,p3,p4;
void create_point()
{	
	center.x = imageWidth/2;
	center.y = imageHeight/2;
	p1.x = (center.y - (rectangle_b*100)/2);
	p1.y = (center.x - (rectangle_a*100)/2);
	p2.x = (center.x - (rectangle_b*100)/2);
	p2.y = (center.x + (rectangle_a*100)/2);
	p3.x = (center.y + (rectangle_b*100)/2);
	p3.y = (center.x - (rectangle_a*100)/2);
	p4.x = (center.y + (rectangle_b*100)/2);
	p4.y = (center.x + (rectangle_a*100)/2);
}
std::ofstream ppmFileStream("task2.ppm", std::ios::out | std::ios::binary);

void fill_rectangle()
{
	ppmFileStream << 30 << " " << 255 << " " << 0 <<"\t";
}

int main()
{
	create_point(); 
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";	
	for(int rowldx = 0 ; rowldx < imageHeight ; rowldx++)
	{	
		for(int colldx=0; colldx < imageWidth; colldx++)
		{
			
			if(p1.x <= rowldx && p1.y <= colldx && p2.y >= colldx)
				fill=1;
			if(p1.x <= rowldx && p2.y < colldx)
                                fill=0;
			if(p4.x <= rowldx)
				fill=0;
			if(fill==1)
				fill_rectangle();
			else if(fill==0)
				ppmFileStream << 169 << " " << " " << 169 << " " << 169 << "\t";
		}
			ppmFileStream << "\n";
	}
	ppmFileStream.close();
	return 0;
}

