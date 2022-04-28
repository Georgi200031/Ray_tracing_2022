#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <stdlib.h>

static const int imageWidth = 1920;
static const int imageHeight = 1080;

class Vector
{
	
	public:
		double X_Dir;
		double Y_Dir;
		double Z_Dir;

	        Vector ();
		Vector(double X_Dir,double Y_Dir, double Z_Dir);
		
		void set(double, double, double);
		
		Vector E(const Vector&) const;				
		Vector operator+(const Vector &) const;
		Vector operator-(const Vector &) const;
		Vector operator*(double) const;

		Vector cross(const Vector&) const;
		
		
		double dot(const Vector& v) const
			{
        			return (X_Dir * v.X_Dir) + (Y_Dir * v.Y_Dir) + (Z_Dir * v.Z_Dir);
			}						
		void find_center()
			{
				X_Dir = X_Dir + 0.5;
                                Y_Dir = Y_Dir + 0.5;
			}
		void convert_raster_to_NDC()
			{
				X_Dir = X_Dir / (imageHeight * (imageWidth / imageHeight));
                                Y_Dir = Y_Dir / imageHeight;
			}
		void convert_NDC_to_screen()
			{
				X_Dir = ((2.0 * X_Dir)-1.0);
				Y_Dir = (1.0 - (2.0 * Y_Dir));
			}			
		void aspect_ratio()
			{
				X_Dir = X_Dir * (imageWidth/imageHeight);
			}
		void MOD()
			{
				X_Dir = abs(X_Dir);
                                Y_Dir = abs(Y_Dir);
                                Z_Dir = abs(Z_Dir);		
			}
		double getLen() const 
			{ 
				return sqrt(X_Dir * X_Dir + Y_Dir * Y_Dir + Z_Dir * Z_Dir); 
			}	
		void normalize() 
			{
            			double len = this->getLen();
            			double coeff = 1 / len;
            			X_Dir = X_Dir * coeff;
            			Y_Dir = Y_Dir * coeff;
            			Z_Dir = Z_Dir * coeff;
        		}		
		void print()
			{
				std::cout<<X_Dir<<" "<<Y_Dir<<" "<<Z_Dir<<std::endl;
			}
};
Vector::Vector()
{
	X_Dir = 0;
	Y_Dir = 0;
	Z_Dir = 0;
}
Vector::Vector(double X_Dir,double Y_Dir,double Z_Dir) //set x,y,z;
{
	this->X_Dir = X_Dir;
	this->Y_Dir = Y_Dir;
	this->Z_Dir = Z_Dir;
}

Vector Vector::operator+(const Vector & v) const
{
	return Vector(X_Dir + v.X_Dir, Y_Dir + v.Y_Dir, Z_Dir + v.Z_Dir);
}

Vector Vector::operator-(const Vector & v) const
{
	return Vector(X_Dir - v.X_Dir, Y_Dir - v.Y_Dir, Z_Dir - v.Z_Dir);
}

Vector Vector::operator*(double v) const
{
	return Vector(X_Dir * v, Y_Dir * v, Z_Dir * v);
}
Vector Vector::cross(const Vector& v) const
{
	 return Vector(Y_Dir * v.Z_Dir - Z_Dir * v.Y_Dir,
	 Z_Dir * v.X_Dir - X_Dir * v.Z_Dir,
         X_Dir * v.Y_Dir - Y_Dir * v.X_Dir); 
}
Vector Vector::E(const Vector& v)const
{
	return Vector(Vector(X_Dir,Y_Dir,Z_Dir).operator-(v));
}

#endif
