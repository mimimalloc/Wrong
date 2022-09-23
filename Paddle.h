#pragma once
#include "Entity.h"
#include "raylib.h"

/**
	[ Paddle ]
	The paddle is manipulated by a player to move
	up and down within a given set of boundaries.

	The goal of the game is to avoid hitting the ball
	with the paddle.
*/
class Paddle : public Entity
{
public:
	Paddle(float x, float y, float defaultSpeed, Vector2 bounds, KeyboardKey upKey, KeyboardKey downKey);

	void Update(float dt);
	void Draw();
	// Speeds up the paddle by a given factor (speed * factor)
	void SpeedUp(float factor);
	// Reset the speed to its default value
	void ResetSpeed();
private:
	// Move the paddle up (within its boundaries)
	void MoveUp(float dt);
	// Move the paddle down (within its boundaries)
	void MoveDown(float dt);

	// The default speed at which the paddle moves
	float defaultSpeed;
	// The current speed at which the paddle moves
	float speed;
	// The boundaries of the paddle's vertical movement (x = top, y = bottom)
	Vector2 bounds;
	// The key the player uses to move the paddle up
	KeyboardKey upKey;
	// The key the player uses to move the paddle down
	KeyboardKey downKey;
};

