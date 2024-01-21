#pragma once

#include "GameLibrary.h"

class Player : public Object2D
{
private:
	float Hp;

public:
	Player();
	Player(Point2D& center, float width, float height);
	~Player();

	void update(float deltatime, const Scene& scene);
	void render();
	void handleInput();
	bool detectCollision(const Scene& scene);
	void changeState();
	void animation();
	void move(float deltatime);
	void gameLogic();
};