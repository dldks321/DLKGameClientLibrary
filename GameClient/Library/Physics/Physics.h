#pragma once
#include"Point.h"
#include"Vector.h"

Point2D calculatePosition2D(const Point2D& initialPosition, const Vector2D& velocity, const Vector2D& acceleration, float time);
Point3D calculatePosition3D(const Point3D& initialPosition, const Vector3D& velocity, const Vector3D& acceleration, float time);