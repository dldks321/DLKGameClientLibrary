#pragma once

struct Point2D
{
	float x, y;

	bool operator== (const Point2D& point);
	bool operator!= (const Point2D& point);

	Point2D operator+ (const Point2D& point);
	Point2D operator- (const Point2D& point);
	Point2D operator* (const float num);
	Point2D operator/ (const float num);

	Point2D& operator= (const Point2D& point);
	Point2D& operator+= (const Point2D& point);
	Point2D& operator-= (const Point2D& point);
	Point2D& operator*= (const float num);
	Point2D& operator/= (const float num);
};

Point2D createPoint2D(float x, float y);

struct Point3D
{
	float x, y, z;

	bool operator== (const Point3D& point);
	bool operator!= (const Point3D& point);

	Point3D operator+ (const Point3D& point);
	Point3D operator- (const Point3D& point);
	Point3D operator* (const float num);
	Point3D operator/ (const float num);

	Point3D& operator= (const Point3D& point);
	Point3D& operator+= (const Point3D& point);
	Point3D& operator-= (const Point3D& point);
	Point3D& operator*= (const float num);
	Point3D& operator/= (const float num);
};

Point3D createPoint3D(float x, float y, float z);