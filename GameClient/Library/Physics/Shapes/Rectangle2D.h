#pragma once
#include"Point.h"

struct Rectangle2D
{
	Point2D center;

	float width;
	float height;
};

Rectangle2D createRectangle(Point2D& center, float width, float height);
