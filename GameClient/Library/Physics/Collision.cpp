#include"Collision.h"

bool collisionDetection2D(const Rectangle2D& rectangle1, const Rectangle2D& rectangle2)
{
	if (rectangle1.center.x - 0.5f * rectangle1.width > rectangle2.center.x + 0.5f * rectangle2.width
		|| rectangle1.center.x + 0.5f * rectangle1.width < rectangle2.center.x - 0.5f * rectangle2.width
		|| rectangle1.center.y - 0.5f * rectangle1.height > rectangle2.center.y + 0.5f * rectangle2.height
		|| rectangle1.center.y + 0.5f * rectangle1.height < rectangle2.center.y - 0.5f * rectangle2.height)
		return false;
	return true;
}

bool collisionDetection3D(const Cylinder3D& cylinder1, const Cylinder3D& cylinder2)
{
	if (cylinder1.center.z - 0.5f * cylinder1.height > cylinder2.center.z + 0.5f * cylinder2.height
		|| cylinder1.center.z + 0.5f * cylinder1.height < cylinder2.center.z - 0.5f * cylinder2.height
		|| (cylinder1.center.x - cylinder2.center.x) * (cylinder1.center.x - cylinder2.center.x) + (cylinder1.center.y - cylinder2.center.y) * (cylinder1.center.y - cylinder2.center.y) >(cylinder1.radius + cylinder2.radius) * (cylinder1.radius + cylinder2.radius))
		return false;
	return true;
}