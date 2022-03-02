#include <fstream>
#include <ctime> 

static const int imageWidth = 1920;
static const int imageHeight = 1080;

static int start_color = 1;
static int new_line = imageWidth/10;
static int color = 1;


static const int maxColorComponent = 255;

struct color{
	int r;
	int g;
	int b;
}red,yellow,green,skyblue,blue;

static void create_Color()
{
	int r = std::rand() % 255 + 0;
        int g = std::rand() % 255 + 0;
        int b = std::rand() % 255 + 0;
        red.r = r; yellow.r = r; green.r = 0; skyblue.r = 0; blue.r = 0; 
        red.g = 0; yellow.g = g; green.g = g; skyblue.g = g; blue.g = 0;
        red.b = 0; yellow.b = 0; green.b = 0; skyblue.b = b; blue.b = b;
}

std::ofstream ppmFileStream("task1.ppm", std::ios::out | std::ios::binary);



int main()
{
	std::srand(std::time(nullptr)); 
	ppmFileStream << "P3\n";
	ppmFileStream << imageWidth << " " << imageHeight << "\n";
	ppmFileStream << maxColorComponent << "\n";	
	for(int rowldx = 0 ; rowldx < imageWidth ; rowldx++)
	{	
		for(int colldx=0; colldx < 10; colldx++)
		{     
			if(colldx==1)
				start_color = color;			
			for(int i=0 ;i<imageWidth/10;i++)
        			{
                        		create_Color();
					if(color==1)
                                		ppmFileStream << red.r << " " << red.g << " " << red.b << "\t";
                        		else if(color==2)
                                		ppmFileStream << yellow.r << " " << yellow.g << " " << yellow.b << "\t";
                        		else if(color==3)
                                		ppmFileStream << green.r << " " << green.g << " " << green.b << "\t";
                        		else if(color==4)
                                		ppmFileStream << skyblue.r << " " << skyblue.g << " " << skyblue.b << "\t";
                        		else if(color==5)
                                		ppmFileStream << blue.r << " " << blue.g << " " << blue.b << "\t";
        			}
			color++;
			if(color==6)color=1;
		}
		if(rowldx == new_line)
			{
				new_line = new_line+(imageWidth/10);
				if(start_color+1 == 6)
					start_color = 1;
				
					color = start_color + 1;
			}
			ppmFileStream << "\n";
	}
	ppmFileStream.close();
	return 0;
}
