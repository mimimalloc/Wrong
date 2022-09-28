#include "Ball.h"

float MAX_BALL_SPEED = 1000.0f;

Ball::Ball(float defaultMoveSpeed):
	Entity(400, 300, 8, 8, 1.0f),
	moveDirection(Vector2 {1, 1}),
	defaultMoveSpeed(defaultMoveSpeed), moveSpeed(defaultMoveSpeed)
{
}

void Ball::Reset(Vector2 dir)
{
	rect.x = 400;
	rect.y = 300;
	moveSpeed = defaultMoveSpeed;
	moveDirection = dir;
}

void Ball::Update(float dt)
{
	if (moveSpeed > MAX_BALL_SPEED) {
		moveSpeed = MAX_BALL_SPEED;
	}

	Move(dt);
}

void Ball::Draw()
{
	DrawCircle(rect.x, rect.y, rect.width, Fade(WHITE, opacity));
}

void Ball::Bounce(BounceDirection dir)
{
	switch (dir) {
	case vertical:
		moveDirection.y *= -1;
		break;
	default:
		moveDirection.x *= -1;
		break;
	}
	moveSpeed *= 1.2;
}

void Ball::Move(float dt)
{
	rect.x += (moveSpeed * dt * moveDirection.x);
	rect.y += (moveSpeed * dt * moveDirection.y);
}
