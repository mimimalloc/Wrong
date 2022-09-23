#pragma once
#include "Entity.h"
#include "raylib.h"

/**
	[ BallBounds ]
	This structure represents the boundaries
	in which the ball resides. If it hits these boundaries,
	the ball will "bounce" off them and reverse its movement
	direction on that axis.
*/
struct BallBounds {
	float x1;
	float x2;
	float y1;
	float y2;
};

/**
	[ Ball ]
	This entity represents the ball for the game.
	Unlike in regular pong, this ball bounces off
	the side walls as well as the ceiling and floor,
	and a player loses if it *hits* their paddle.

	The ball is in constant motion and increases in
	speed with each bounce, up to a maximum that is
	difficult but not impossible to keep track of.
*/
class Ball : public Entity
{
public:
	Ball(BallBounds boundary, float defaultMoveSpeed);

	// Resets the ball to its starting position and speed, moving towards the
	// given vector direction
	void Reset(Vector2 dir);

	void Update(float dt);
	void Draw();
private:
	// Checks whether the ball is colliding with the walls, and adjusts it if so
	void CheckWallCollisions();
	// Moves the ball forward with its current speed and direction
	void Move(float dt);

	// The direction the ball is moving. The ball always moves at a diagonal
	// with the x and y each being either 1 or -1.
	// (1, 1) moves towards the bottom right, while
	// (-1, -1) moves towards the top left
	Vector2 moveDirection;

	// The default move speed of the ball and what it is reset to
	float defaultMoveSpeed;

	// The current move speed of the ball
	float moveSpeed;

	// The coordinates of the walls the ball bounces off of
	BallBounds boundary;
};

