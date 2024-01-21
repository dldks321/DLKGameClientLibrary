#include"Vector.h"
#include<cmath>

bool Vector2D::operator== (const Vector2D& vector)
{
	if (x == vector.x && y == vector.y)
		return true;
	return false;
}

bool Vector2D::operator!= (const Vector2D& vector)
{
	if (x == vector.x && y == vector.y)
		return false;
	return true;
}

Vector2D Vector2D::operator+ (const Vector2D& vector)
{
	return createVector2D(x + vector.x, y + vector.y);
}

Vector2D Vector2D::operator- (const Vector2D& vector)
{
	return createVector2D(x - vector.x, y - vector.y);
}

Vector2D Vector2D::operator* (const float num)
{
	return createVector2D(x * num, y * num);
}

Vector2D Vector2D::operator/ (const float num)
{
	return createVector2D(x / num, y / num);
}

Vector2D& Vector2D::operator= (const Vector2D& vector)
{
	x = vector.x;
	y = vector.y;
	return *this;
}

Vector2D& Vector2D::operator+= (const Vector2D& vector)
{
	x += vector.x;
	y += vector.y;
	return *this;
}

Vector2D& Vector2D::operator-= (const Vector2D& vector)
{
	x -= vector.x;
	y -= vector.y;
	return *this;
}

Vector2D& Vector2D::operator*= (const float num)
{
	x *= num;
	y *= num;
	return *this;
}

Vector2D& Vector2D::operator/= (const float num)
{
	x /= num;
	y /= num;
	return *this;
}

Vector2D createVector2D(float x, float y)
{
	return Vector2D{ x, y };
}

float dotProductVector2D(const Vector2D& vector1, const Vector2D& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y;
}

float magnitudeVector2D(const Vector2D& vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y);
}

Vector2D normalizingVector2D(const Vector2D& vector)
{
	float magnitude = magnitudeVector2D(vector);
	return createVector2D(vector.x / magnitude, vector.y / magnitude);
}

bool Vector3D::operator== (const Vector3D& vector)
{
	if (x == vector.x && y == vector.y && z == vector.z)
		return true;
	return false;
}

bool Vector3D::operator!= (const Vector3D& vector)
{
	if (x == vector.x && y == vector.y && z == vector.z)
		return false;
	return true;
}

Vector3D Vector3D::operator+ (const Vector3D& vector)
{
	return createVector3D(x + vector.x, y + vector.y, z + vector.z);
}

Vector3D Vector3D::operator- (const Vector3D& vector)
{
	return createVector3D(x - vector.x, y - vector.y, z - vector.z);
}

Vector3D Vector3D::operator* (const float num)
{
	return createVector3D(x * num, y * num, z * num);
}

Vector3D Vector3D::operator/ (const float num)
{
	return createVector3D(x / num, y / num, z / num);
}

Vector3D& Vector3D::operator= (const Vector3D& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	return *this;
}

Vector3D& Vector3D::operator+= (const Vector3D& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	return *this;
}

Vector3D& Vector3D::operator-= (const Vector3D& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	return *this;
}

Vector3D& Vector3D::operator*= (const float num)
{
	x *= num;
	y *= num;
	z *= num;
	return *this;
}

Vector3D& Vector3D::operator/= (const float num)
{
	x /= num;
	y /= num;
	z /= num;
	return *this;
}

Vector3D createVector3D(float x, float y, float z)
{
	return Vector3D{ x, y, z };
}

float dotProductVector3D(const Vector3D& vector1, const Vector3D& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z;
}

Vector3D crossProductVector3D(const Vector3D& vector1, const Vector3D& vector2)
{
	return createVector3D(vector1.y * vector2.z - vector1.z * vector2.y, vector1.z * vector2.x - vector1.x * vector2.z, vector1.x * vector2.y - vector1.y * vector2.x);
}

float magnitudeVector3D(const Vector3D& vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z);
}

Vector3D normalizingVector3D(const Vector3D& vector)
{
	float magnitude = magnitudeVector3D(vector);
	return createVector3D(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude);
}

bool Vector4D::operator== (const Vector4D& vector)
{
	if (x == vector.x && y == vector.y && z == vector.z && w == vector.w)
		return true;
	return false;
}

bool Vector4D::operator!= (const Vector4D& vector)
{
	if (x == vector.x && y == vector.y && z == vector.z && w == vector.w)
		return false;
	return true;
}

Vector4D Vector4D::operator+ (const Vector4D& vector)
{
	return createVector4D(x + vector.x, y + vector.y, z + vector.z, w + vector.w);
}

Vector4D Vector4D::operator- (const Vector4D& vector)
{
	return createVector4D(x - vector.x, y - vector.y, z - vector.z, w - vector.w);
}

Vector4D Vector4D::operator* (const float num)
{
	return createVector4D(x * num, y * num, z * num, w * num);
}

Vector4D Vector4D::operator/ (const float num)
{
	return createVector4D(x / num, y / num, z / num, w / num);
}

Vector4D& Vector4D::operator= (const Vector4D& vector)
{
	x = vector.x;
	y = vector.y;
	z = vector.z;
	w = vector.w;
	return *this;
}

Vector4D& Vector4D::operator+= (const Vector4D& vector)
{
	x += vector.x;
	y += vector.y;
	z += vector.z;
	w += vector.w;
	return *this;
}

Vector4D& Vector4D::operator-= (const Vector4D& vector)
{
	x -= vector.x;
	y -= vector.y;
	z -= vector.z;
	w -= vector.w;
	return *this;
}

Vector4D& Vector4D::operator*= (const float num)
{
	x *= num;
	y *= num;
	z *= num;
	w *= num;
	return *this;
}

Vector4D& Vector4D::operator/= (const float num)
{
	x /= num;
	y /= num;
	z /= num;
	w /= num;
	return *this;
}

Vector4D createVector4D(float x, float y, float z, float w)
{
	return Vector4D{ x, y, z, w };
}

float dotProductVector4D(const Vector4D& vector1, const Vector4D& vector2)
{
	return vector1.x * vector2.x + vector1.y * vector2.y + vector1.z * vector2.z + vector1.w * vector2.w;
}

float magnitudeVector4D(const Vector4D& vector)
{
	return sqrt(vector.x * vector.x + vector.y * vector.y + vector.z * vector.z + vector.w * vector.w);
}

Vector4D normalizingVector4D(const Vector4D& vector)
{
	float magnitude = magnitudeVector4D(vector);
	return createVector4D(vector.x / magnitude, vector.y / magnitude, vector.z / magnitude, vector.w / magnitude);
}