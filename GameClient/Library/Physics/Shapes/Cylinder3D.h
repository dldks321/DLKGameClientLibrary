#pragma once
#include"Point.h"

struct Cylinder3D
{
	Point3D center;

	float radius;
	float height;
};

Cylinder3D createCylinder(Point3D& center, float width, float height);