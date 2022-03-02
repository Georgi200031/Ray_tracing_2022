#include <fstream> 

static const int imageWidth = 1920;
static const int imageHeight = 1080;

static const int maxColorComponent = 255;

static const int trapeze_h = 1;
static const int trapeze_a = 2;

static bool fill=0;

struct trapeze{
	int x;
	int y;
}p1,p2,center,p3,p_1,p_2;
void create_point()
{	
	center.x = imageHeight/2;
	center.y = imageWidth/2;
	p1.x = (center.x - (trapeze_h*100)/2);
	p1.y = center.y;
	p2.x = (center.x + (trapeze_h*100)/2);
	p2.y = (center.y - (trapeze_a*100)/2);
	p3.x = (center.x + (trapeze_h*100)/2);
	p3.y = (center.y + (trapeze_a*100)/2);
	p_1.x = p1.x;
	p_1.y = p1.y;
	p_2.x = p1.x;
	p_2.y = p1.y;
}
std::ofstream ppmFileStream("task2-trapeze.ppm", std::ios::out | std::ios::binary);

void fill_trapeze()
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
	
			if(p1.x <= rowldx && p_1.y <= colldx && p_2.y >= colldx)
				fill=1;
			if(p1.x <= rowldx && p_2.y < colldx)
                                fill=0;
			if(p3.x <= rowldx)
				fill=0;
			if(fill==1)
				fill_trapeze();
			else if(fill==0)
				ppmFileStream << 169 << " " << " " << 169 << " " << 169 << "\t";
		}
		p_1.x=p_1.x+1;
		p_1.y=p_1.y-1;
		p_2.x=p_2.x+1;
		p_2.y=p_2.y+1;
		ppmFileStream << "\n";
	}
	ppmFileStream.close();
	return 0;
}


