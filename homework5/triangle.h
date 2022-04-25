#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "vector.h"
class Triangle
{
	public: 
		double x,y,z;
		//Vector vert[3];
		//Vector vertOne;
		//Vector vertTwo;
		//Vector vertThree;
  		//Triangle();
		//double vertOneX,vertOneY,vertOneZ;
		//double vertTwoX,vertTwoY,vertTwoZ;
		//double vertThreeX,vertThreeY,vertThreeZ;	
		//Triangle(double vertOneX,double vertOneY,double vertOneZ,
		//	 double vertTwoX,double vertTwoY,double vertTwoZ,
		//	 double vertThreeX,double vertThreeY,double vertThreeZ);
		Triangle(const Vector& v0, const Vector& v1, const Vector& v2);
		//Triangle(const Vector&, const Vector&, const Vector&);
		
		
	private:
		
        	Vector vert[3];
       //		Vector n;
     
};
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


/*Triangle::Triangle(double vertOneX,double vertOneY,double vertOneZ,
                         double vertTwoX,double vertTwoY,double vertTwoZ,
                         double vertThreeX,double vertThreeY,double vertThreeZ)
{
	this->vertOneX = vertOneX;
	this->vertOneY = vertOneY;
	this->vertOneZ = vertOneZ;
	this->vertTwoX = vertTwoX;
        this->vertTwoY = vertTwoY;
        this->vertTwoZ = vertTwoZ;
	this->vertThreeX = vertThreeX;
        this->vertThreeY = vertThreeY;
        this->vertThreeZ = vertThreeZ;
}
*/
#endif
