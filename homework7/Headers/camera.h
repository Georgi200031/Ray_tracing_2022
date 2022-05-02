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
		
		void orientation(const Matrix&);
		void dolly(double dist);
		void truck(double dist);
		void pedestal(double dist);
		void pan(double angle);
		void tilt(double angle);
		void roll(double angle);	
};
void Camera::orientation(const Matrix& rotMat)
{
	Matrix mat = rotMat;
	Ray = mat.operator*(Ray);
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
