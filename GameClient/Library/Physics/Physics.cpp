#include"Physics.h"
#include"Point.h"

Point2D calculatePosition2D(const Point2D& initialPosition, const Vector2D& velocity, const Vector2D& acceleration, float time)
{
	return createPoint2D(
		initialPosition.x + (velocity.x * time) + (0.5f * acceleration.x * time * time),
		initialPosition.y + (velocity.y * time) + (0.5f * acceleration.y * time * time)
	);
}

Point3D calculatePosition3D(const Point3D& initialPosition, const Vector3D& velocity, const Vector3D& acceleration, float time)
{
	return createPoint3D(
		initialPosition.x + (velocity.x * time) + (0.5f * acceleration.x * time * time),
		initialPosition.y + (velocity.y * time) + (0.5f * acceleration.y * time * time),
		initialPosition.z + (velocity.z * time) + (0.5f * acceleration.z * time * time)
	);
}