#pragma once

struct Vector2D
{
	float x, y;

	bool operator== (const Vector2D& vector);
	bool operator!= (const Vector2D& vector);

	Vector2D operator+ (const Vector2D& vector);
	Vector2D operator- (const Vector2D& vector);
	Vector2D operator* (const float num);
	Vector2D operator/ (const float num);

	Vector2D& operator= (const Vector2D& vector);
	Vector2D& operator+= (const Vector2D& vector);
	Vector2D& operator-= (const Vector2D& vector);
	Vector2D& operator*= (const float num);
	Vector2D& operator/= (const float num);
};

Vector2D createVector2D(float x, float y);
float dotProductVector2D(const Vector2D& vector1, const Vector2D& vector2);
float magnitudeVector2D(const Vector2D& vector);
Vector2D normalizingVector2D(const Vector2D& vector);

struct Vector3D
{
	float x, y, z;

	bool operator== (const Vector3D& vector);
	bool operator!= (const Vector3D& vector);

	Vector3D operator+ (const Vector3D& vector);
	Vector3D operator- (const Vector3D& vector);
	Vector3D operator* (const float num);
	Vector3D operator/ (const float num);

	Vector3D& operator= (const Vector3D& vector);
	Vector3D& operator+= (const Vector3D& vector);
	Vector3D& operator-= (const Vector3D& vector);
	Vector3D& operator*= (const float num);
	Vector3D& operator/= (const float num);
};

Vector3D createVector3D(float x, float y, float z);
float dotProductVector3D(const Vector3D& vector1, const Vector3D& vector2);
Vector3D crossProductVector3D(const Vector3D& vector1, const Vector3D& vector2);
float magnitudeVector3D(const Vector3D& vector);
Vector3D normalizingVector3D(const Vector3D& vector);

struct Vector4D
{
	float x, y, z, w;

	bool operator== (const Vector4D& vector);
	bool operator!= (const Vector4D& vector);

	Vector4D operator+ (const Vector4D& vector);
	Vector4D operator- (const Vector4D& vector);
	Vector4D operator* (const float num);
	Vector4D operator/ (const float num);

	Vector4D& operator= (const Vector4D& vector);
	Vector4D& operator+= (const Vector4D& vector);
	Vector4D& operator-= (const Vector4D& vector);
	Vector4D& operator*= (const float num);
	Vector4D& operator/= (const float num);
};

Vector4D createVector4D(float x, float y, float z, float w);
float dotProductVector4D(const Vector4D& vector1, const Vector4D& vector2);
float magnitudeVector4D(const Vector4D& vector);
Vector4D normalizingVector4D(const Vector4D& vector);