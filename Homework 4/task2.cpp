#include <iostream>
struct A
{
	double x,y,z;
}A_point;

struct B
{
	double x,y,z;
}B_point;

struct C
{
	double x,y,z;
}C_point;	

void cross()
{
	       C_point.x = A_point.y * B_point.z - A_point.z * B_point.y; 
	       C_point.y = A_point.z * B_point.x - A_point.x * B_point.z;
	       C_point.z = A_point.x * B_point.y - A_point.y * B_point.x;
}

double S()
{
	return sqrt(pow(C_point.x,2)+pow(C_point.y,2)+pow(C_point.z,2));
}

int main()
{
//first
	A_point.x = 3.5;
        A_point.y = 0;
	A_point.z = 0;
		
	B_point.x = 1.75;
	B_point.y = 3.5;
	B_point.z = 0;

	cross();
		
	std::cout<<"C("<<C_point.x<< "," <<C_point.y<<","<<C_point.z<<")"<<std::endl;
	std::cout<<"S_fisrt:"<<S()<<std::endl;
//second
	A_point.x = 3;
        A_point.y = -3;
        A_point.z = 1;
                
        B_point.x = 4;
        B_point.y = 9;
        B_point.z = 3;
        
        cross();

        std::cout<<"C("<<C_point.x<< "," <<C_point.y<<","<<C_point.z<<")"<<std::endl;
	std::cout<<"S_second:"<<S()<<std::endl;

	return 0;
}
