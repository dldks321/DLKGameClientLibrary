#include"Color.h"

Color4f& Color4f::operator= (const Color4f& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
	return *this;
}

Color4f& Color4f::operator= (const Color4b& c)
{
	r = c.r / 255.0f;
	g = c.g / 255.0f;
	b = c.b / 255.0f;
	a = c.a / 255.0f;
	return *this;
}

Color4f createColor4f(float r, float g, float b, float a)
{
	return Color4f{ r, g, b, a };
}

Color4b& Color4b::operator= (const Color4b& c)
{
	r = c.r;
	g = c.g;
	b = c.b;
	a = c.a;
	return *this;
}

Color4b& Color4b::operator= (const Color4f& c)
{
	r = (byte)(c.r * 0xFF);
	g = (byte)(c.g * 0xFF);
	b = (byte)(c.b * 0xFF);
	a = (byte)(c.a * 0xFF);
	return *this;
}

Color4b createColor4b(byte r, byte g, byte b, byte a)
{
	return Color4b{ r, g, b, a };
}