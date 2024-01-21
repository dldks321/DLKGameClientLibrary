#pragma once

#include"Point.h"
#include"Vector.h"
#include"Rectangle2D.h"
#include"Define.h"
#include"Scene.h"

class Object2D 
{
private:
	char* Name;
	Point2D Position;
	Vector2D Velocity;
	Vector2D Acceleration;
	Vector2D Direction;
	Rectangle2D CollisionBound;
	ObjectState State;
	//Image Image;

public:
	Object2D(char* name);
	Object2D(char* name, Point2D& center, float width, float height);
	~Object2D();

	void update(float deltatime, const Scene& scene);
	void changeState();
	void move(float deltatime);
	bool detectCollision(const Scene& scene);
	void animation();
	void render();
};