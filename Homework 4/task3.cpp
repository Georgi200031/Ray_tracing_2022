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

struct Normal_vec
{
	double x,y,z;
}N_vec;
double S()
{
        return sqrt(pow(C_point.x,2)+pow(C_point.y,2)+pow(C_point.z,2))/2;
}

void find_normal_vecor()
{
	       N_vec.x = C_point.x / S() / 2;
	       N_vec.y = C_point.y / S() / 2;
	       N_vec.z = C_point.z / S() / 2;	   	     
}

int main()
{
//first_triangle
	A_point.x = -1.75;
        A_point.y = -1.75;
	A_point.z = -3;
		
	B_point.x = 1.75;
	B_point.y = -1.75;
	B_point.z = -3;

	C_point.x = 0;
	C_point.y = 1.75;
	C_point.z = -3;
		
	std::cout<<"Normal_vector("<<N_vec.x<< "," <<N_vec.y<<","<<N_vec.z<<")"<<std::endl;
	std::cout<<"S_fisrt:"<<S()<<std::endl;
//second
	A_point.x = 0;
        A_point.y = 0;
        A_point.z = -1;

        B_point.x = 1;
        B_point.y = 0;
        B_point.z = 1;

        C_point.x = -1;
        C_point.y = 1;
        C_point.z = 0;

        std::cout<<"Normal_vector("<<N_vec.x<< "," <<N_vec.y<<","<<N_vec.z<<")"<<std::endl;
        std::cout<<"S_fisrt:"<<S()<<std::endl;
//tirdth
        A_point.x = 0.56;
        A_point.y = 1.11;
        A_point.z = 1.23;

        B_point.x = 0.44;
        B_point.y = -2.368;
        B_point.z = -0.54;

        C_point.x = -1.56;
        C_point.y = 0.15;
        C_point.z = -1.92;

        std::cout<<"Normal_vector("<<N_vec.x<< "," <<N_vec.y<<","<<N_vec.z<<")"<<std::endl;
        std::cout<<"S_fisrt:"<<S()<<std::endl;
	return 0;
}

