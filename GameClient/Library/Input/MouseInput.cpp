#include "MouseInput.h"

MouseInput::MouseInput()
{
	mousePos = createPoint2D(0, 0);
	mouseLeftState = KeyStateUp;
	mouseRightState = KeyStateUp;
	mouseWheelDelta = 0;
}

MouseInput::~MouseInput()
{

}

void MouseInput::updateMouseClick(Direction direction, KeyState state, Point2D point)
{
	switch (direction)
	{
		case Left:
		{
			mouseLeftState = state;
			break;
		}
		case Right:
		{
			mouseRightState = state;
			break;
		}
	}
	mousePos = point;
	//printf_s("mouse state updated %d %d %f %f\n", mouseLeftState, mouseRightState, mousePos.x, mousePos.y);
}

void MouseInput::updateMouseMove(KeyState state, Point2D point)
{
	mouseLeftState = state;
	mouseRightState = state;
	mousePos = point;
	//printf_s("mouse state updated %d %d %f %f\n", mouseLeftState, mouseRightState, mousePos.x, mousePos.y);
}

void MouseInput::updateMouseWheel(int delta)
{
	mouseWheelDelta = delta;
	//printf_s("wheel state updated %d\n", mouseWheelDelta);
}