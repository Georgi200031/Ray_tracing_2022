#ifndef MATRIX_H
#define MATRIX_H
#include "vector.h"

#define PI 3.14159265

class Matrix
{
	public:
		double m[3][3];
		Matrix(); 
		Matrix(double m00,double m01,double m02,double m10, double m11, double m12,double m20,double m21, double m22);
		Vector operator* (const Vector& v1);
		Matrix createRotationX(double angle);
		Matrix createRotationY(double angle);
		Matrix createRotationZ(double angle);
		void print();
};

Matrix::Matrix()
{
	for(int i = 0; i < 3 ;i++)
	{
		for(int j = 0;j < 3; j++)
		{
			m[i][j] = 0;
		}
	}
} 
Matrix::Matrix(double m00,double m01,double m02,double m10, double m11, double m12,double m20,double m21, double m22)
{
	m[0][0] = m00;
	m[0][1] = m01;
	m[0][2] = m02;
	
	m[1][0] = m10;
	m[1][1] = m11;
	m[1][2] = m12;
		
	m[2][0] = m20;
	m[2][1] = m21;
	m[2][2] = m22;

}
Vector Matrix::operator*(const Vector& v)
{
	return Vector(
		v.X_Dir * m[0][0] + v.Y_Dir * m[0][1] - v.Z_Dir * m[0][2],
		v.X_Dir * m[1][0] + v.Y_Dir * m[1][1] + v.Z_Dir * m[1][2],
		v.X_Dir * m[2][0] + v.Y_Dir * m[2][1] + v.Z_Dir * m[2][2] 
		);	
}
Matrix Matrix::createRotationX(double angle)
{
        double c = cos(angle*PI/180);
        double s = sin(angle*PI/180);
        return Matrix(
                1, 0,  0,
      		0, c, -s,
      		0, s,  c
                );
}

Matrix Matrix::createRotationY(double angle)
{
	double c = cos(angle*PI/180);
	double s = sin(angle*PI/180);
	return Matrix(
		c , 0 , -s,
		0 , 1 ,  0,
		s , 0 ,  c
		);
}
Matrix Matrix::createRotationZ(double angle)
{
        double c = cos(angle*PI/180);
        double s = sin(angle*PI/180);
        return Matrix(
                c, -s, 0,
      		s,  c, 0,
      		0,  0, 1
                );
}

void Matrix::print()
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			{
				std::cout<<m[i][j]<<" "<<std::endl;
			}
}
#endif
