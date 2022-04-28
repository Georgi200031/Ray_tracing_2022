#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vector.h"
class Triangle
{
	public:
		Vector vert[3];
		Triangle();
		Triangle(const Vector& v0, const Vector& v1, const Vector& v2);			
		Vector E0() { return Vector(vert[1].E(vert[0])); }
		Vector E1() { return Vector(vert[2].E(vert[1])); } 
		Vector E2() { return Vector(vert[0].E(vert[2])); }
		Vector normal() 
			{
				Vector result = Vector(E0().cross(E1()));
				result.normalize();
				result.MOD();
				return result; 
			}
		Vector V0P (const Vector& p){ return Vector(p.operator-(vert[0])); }
		Vector V1P (const Vector& p){ return Vector(p.operator-(vert[1])); }
		Vector V2P (const Vector& p){ return Vector(p.operator-(vert[2])); }

		void print(const Vector& v) const
			{
				std::cout<<v.X_Dir<<" "<<v.Y_Dir<<" "<<v.Z_Dir<<std::endl;
			}
};
	
Triangle::Triangle()
{
	this->vert[0].X_Dir = 0;
	this->vert[0].Y_Dir = 0;
	this->vert[0].Z_Dir = 0;
	
	this->vert[1].X_Dir = 0;
	this->vert[1].Y_Dir = 0;
	this->vert[1].Z_Dir = 0;
		
	this->vert[2].X_Dir = 0;
	this->vert[2].Y_Dir = 0;
	this->vert[2].Z_Dir = 0;
}

Triangle::Triangle(const Vector& v0, const Vector& v1, const Vector& v2)
{
	this->vert[0].X_Dir = v0.X_Dir;
	this->vert[0].Y_Dir = v0.Y_Dir;
	this->vert[0].Z_Dir = v0.Z_Dir;
	
	this->vert[1].X_Dir = v1.X_Dir;
	this->vert[1].Y_Dir = v1.Y_Dir;
	this->vert[1].Z_Dir = v1.Z_Dir;
		
	this->vert[2].X_Dir = v2.X_Dir;
	this->vert[2].Y_Dir = v2.Y_Dir;
	this->vert[2].Z_Dir = v2.Z_Dir;
}

#endif
