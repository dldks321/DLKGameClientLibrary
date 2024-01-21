#pragma once

#include "GameLibrary.h"

class MouseInput
{
private:
	Point2D mousePos;
	KeyState mouseLeftState;
	KeyState mouseRightState;
	int mouseWheelDelta;
public:
	MouseInput();
	~MouseInput();

	void updateMouseClick(Direction direction, KeyState state, Point2D point);
	void updateMouseMove(KeyState state, Point2D point);
	void updateMouseWheel(int delta);
};