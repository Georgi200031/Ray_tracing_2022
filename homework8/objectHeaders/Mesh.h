#pragma once
#include <vector>
#include "Vector.h"
#include "Triangle.h"

class Mesh {
public:
	//Getters
	Vector getVertecs(int index) {
		return verts[index];
	}
	Triangle getTriangle(int index) {
		return triangles[index];
	}
	int getObject() {
		return objects;
	}
	int size() {
		return triangles.size();
	}
	//Setters
	void setVertecs(Vector vert) {
		verts.__emplace_back(vert);
	}
	void setTriangles(Triangle triangle) {
		triangles.__emplace_back(triangle);
	}
	void setObject(int k) {
		objects = k;
	}
	void clearVertecs() {
		verts.clear();
	}
private:
	std::vector<Vector> verts;
	std::vector<Triangle> triangles;
	int objects;
	std::vector<Triangle> alltriangle;
};