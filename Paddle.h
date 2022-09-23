#pragma once
#include "Entity.h"
#include "raylib.h"

class Paddle : public Entity
{
public:
	Paddle(float x, float y, float defaultSpeed, Vector2 bounds, KeyboardKey upKey, KeyboardKey downKey);

	void Update(float dt);
	void Draw();
	void SpeedUp(float factor);
	void ResetSpeed();
private:
	void MoveUp(float dt);
	void MoveDown(float dt);

	float defaultSpeed;
	float speed;
	Vector2 bounds;
	KeyboardKey upKey;
	KeyboardKey downKey;
};

