#include "Point.h"

bool Point2D::operator== (const Point2D& point)
{
	if (x == point.x && y == point.y)
		return true;
	return false;
}

bool Point2D::operator!= (const Point2D& point)
{
	if (x == point.x && y == point.y)
		return false;
	return true;
}

Point2D Point2D::operator+ (const Point2D& point)
{
	return createPoint2D(x + point.x, y + point.y);
}

Point2D Point2D::operator- (const Point2D& point)
{
	return createPoint2D(x - point.x, y - point.y);
}

Point2D Point2D::operator* (const float num)
{
	return createPoint2D(x * num, y * num);
}

Point2D Point2D::operator/ (const float num)
{
	return createPoint2D(x / num, y / num);
}

Point2D& Point2D::operator= (const Point2D& point)
{
	x = point.x;
	y = point.y;
	return *this;
}

Point2D& Point2D::operator+= (const Point2D& point)
{
	x += point.x;
	y += point.y;
	return *this;
}

Point2D& Point2D::operator-= (const Point2D& point)
{
	x -= point.x;
	y -= point.y;
	return *this;
}

Point2D& Point2D::operator*= (const float num)
{
	x *= num;
	y *= num;
	return *this;
}

Point2D& Point2D::operator/= (const float num)
{
	x /= num;
	y /= num;
	return *this;
}

Point2D createPoint2D(float x, float y)
{
	return Point2D{ x, y };
}

bool Point3D::operator== (const Point3D& point)
{
	if (x == point.x && y == point.y, z == point.z)
		return true;
	return false;
}

bool Point3D::operator!= (const Point3D& point)
{
	if (x == point.x && y == point.y, z == point.z)
		return true;
	return false;
}

Point3D Point3D::operator+ (const Point3D& point)
{
	return createPoint3D(x + point.x, y + point.y, z + point.z);
}

Point3D Point3D::operator- (const Point3D& point)
{
	return createPoint3D(x - point.x, y - point.y, z - point.z);
}

Point3D Point3D::operator* (const float num)
{
	return createPoint3D(x * num, y * num, z * num);
}

Point3D Point3D::operator/ (const float num)
{
	return createPoint3D(x / num, y / num, z / num);
}

Point3D& Point3D::operator= (const Point3D& point)
{
	x = point.x;
	y = point.y;
	z = point.z;
	return *this;
}

Point3D& Point3D::operator+= (const Point3D& point)
{
	x += point.x;
	y += point.y;
	z += point.z;
	return *this;
}

Point3D& Point3D::operator-= (const Point3D& point)
{
	x -= point.x;
	y -= point.y;
	z -= point.z;
	return *this;
}

Point3D& Point3D::operator*= (const float num)
{
	x *= num;
	y *= num;
	z *= num;
	return *this;
}

Point3D& Point3D::operator/= (const float num)
{
	x /= num;
	y /= num;
	z /= num;
	return *this;
}

Point3D createPoint3D(float x, float y, float z)
{
	return Point3D{ x, y, z };
}