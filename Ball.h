#pragma once
#include "Entity.h"
#include "raylib.h"

struct BallBounds {
	float x1;
	float x2;
	float y1;
	float y2;
};

class Ball : public Entity
{
public:
	Ball(BallBounds boundary, float defaultMoveSpeed);

	void Update(float dt);
	void Draw();
private:
	void CheckWallCollisions();
	void Move(float dt);

	Vector2 moveDirection;
	float defaultMoveSpeed;
	float moveSpeed;
	BallBounds boundary;
};

