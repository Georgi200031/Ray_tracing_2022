#pragma once
#include "Vector.h"

static const int vertsInTriangle = 3;

class Triangle {
public:
	Triangle(const Vector& v0, const Vector& v1, const Vector& v2);
	//Get vertex of the triangle between 0 and 2 vertex
	Vector v(int index) const;
	//calculate vectors of triangle
	Vector E0()const;
	Vector E1()const;
	Vector E2()const;
	//Getter
	Vector getNormal()const {
		Vector n = normal;
		n.normalize();
		return n;
	};
private:
	//verts in triangle
	Vector verts[vertsInTriangle];
	//store normal vector of trianglew
	Vector normal;
};
Triangle::Triangle(const Vector& v0, const Vector& v1, const Vector& v2) {
	//calculate normal
	verts[0] = v0;
	verts[1] = v1;
	verts[2] = v2;
	normal = (v1 - v0).cross(v2 - v0);
	normal.normalize();
}
Vector Triangle::v(int index) const {
	assert(index >= 0 && index < 3);
	return verts[index];
}
Vector Triangle::E0() const {
	return Vector(verts[1] - verts[0]);
}
Vector Triangle::E1() const {
	return Vector(verts[2] - verts[1]);
}
Vector Triangle::E2() const {
	return Vector(verts[0] - verts[2]);
}