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
		void pan(double angle);
		void truck(double dist);
		void tilt(double angle);
		void roll(double angle);
};
void Camera::truck(double dist)
{
	Ray = Ray.operator+(Vector(Ray.X_Dir + dist, Ray.Y_Dir, Ray.Z_Dir));
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
