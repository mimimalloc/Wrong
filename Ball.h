#pragma once
#include "Entity.h"
#include "raylib.h"

/**
	[ BounceDirection ]
	Directions the ball can bounce (vertical or horizontal)
*/
enum BounceDirection {
	vertical, horizontal
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
	Ball(float defaultMoveSpeed);

	// Resets the ball to its starting position and speed, moving towards the
	// given vector direction
	void Reset(Vector2 dir);

	void Update(float dt);
	void Draw();

	// "Bounces" the ball, reversing its trajectory along the 
	// vertical or horizontal axis
	void Bounce(BounceDirection dir);
private:
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
};

