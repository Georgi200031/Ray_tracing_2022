#ifndef CAMERA_H
#define CAMERA_H
#include "matrix.h"
//#include "vector.h"
class Camera
{
	public:
		Vector Ray;
		Vector Pos; 
		Vector Origin;
		void orientation();
		void dolly(double dist);
		void truck(double dist);
		void pedestal(double dist);
		void pan(double angle);
		void tilt(double angle);
		void roll(double angle);	
};
void Camera::orientation(double a1,double a2,double a3,
			 double a4,double a5,double a6,
			 double a7,double a8,double a9)
{
	Matrix mat = Matrix(a1,a2,a3,a4,a5,a6,a7,a8,a9);
	Ray = Mat.operator*(Ray);
}
void Camera::dolly(double dist)
{
	Ray = Ray.operator+(Vector(Ray.X_Dir, Ray.Y_Dir, Ray.Z_Dir + dist));
}
void Camera::truck(double dist)
{
	Ray = Ray.operator+(Vector(Ray.X_Dir + dist, Ray.Y_Dir, Ray.Z_Dir));
}
void Camera::pedestal(double dist)
{
	Ray = Ray.operator+(Vector(Ray.X_Dir, Ray.Y_Dir + dist, Ray.Z_Dir));
}
void Camera::pan(double angle)
{
	Matrix Pan;
	Matrix camRotMat = Pan.createRotationY(angle);
	Ray = camRotMat.operator*(Ray);
}
void Camera::tilt(double angle)
{
	Matrix Tilt;
        Matrix camRotMat = Tilt.createRotationX(angle);
        Ray = camRotMat.operator*(Ray);
}
void Camera::roll(double angle)
{
	Matrix Roll;
	Matrix camRotMat = Roll.createRotationZ(angle);
	Ray = camRotMat.operator*(Ray);
}
#endif
