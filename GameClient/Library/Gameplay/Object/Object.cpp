#include"Object.h"
#include"Physics.h"

Object2D::Object2D(char* name)
{
	Name = name;
	Position = createPoint2D(0, 0);
	Velocity = createVector2D(0, 0);
	Acceleration = createVector2D(0, 0);
	Direction = createVector2D(0, 0);
	CollisionBound = createRectangle(Position, 0, 0);
	State = Stop;
}

Object2D::Object2D(char* name, Point2D& center, float width, float height)
{
	Name = name;
	Position = center;
	Velocity = createVector2D(0, 0);
	Acceleration = createVector2D(0, 0);
	Direction = createVector2D(0, 0);
	CollisionBound = createRectangle(center, width, height);
	State = Stop;
}

Object2D::~Object2D()
{
		
}

void Object2D::update(float deltatime, const Scene& scene)
{
	changeState();
	move(deltatime);
	detectCollision(scene);
	animation();
	render();
}

void Object2D::changeState()
{

}

void Object2D::move(float deltatime)
{
	Position = calculatePosition2D(Position, Velocity, Acceleration, deltatime);
}

bool Object2D::detectCollision(const Scene& scene)
{
	return false;
}

void Object2D::animation()
{

}

void Object2D::render()
{

}
