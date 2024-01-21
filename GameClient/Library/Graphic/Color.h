#pragma once

#include"Define.h"

struct Color4f;
struct Color4b;

struct Color4f
{
	float r, g, b, a;

	Color4f& operator= (const Color4f& c);
	Color4f& operator= (const Color4b& c);
};

Color4f createColor4f(float r, float g, float b, float a);

struct Color4b
{
	byte r, g, b, a;

	Color4b& operator= (const Color4b& c);
	Color4b& operator= (const Color4f& c);
};

Color4b createColor4b(byte r, byte g, byte b, byte a);