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

/*
void Ball::CheckWallCollisions()
{
	if (rect.x <= boundary.x1) {
		rect.x = boundary.x1;
		moveDirection.x = 1;
		moveSpeed *= 1.1;
	} else if (rect.x >= boundary.x2) {
		rect.x = boundary.x2;
		moveDirection.x = -1;
		moveSpeed *= 1.1;
	}

	if (rect.y <= boundary.y1) {
		rect.y = boundary.y1;
		moveDirection.y = 1;
		moveSpeed *= 1.1;
	} else if (rect.y >= boundary.y2) {
		rect.y = boundary.y2;
		moveDirection.y = -1;
		moveSpeed *= 1.1;
	}
}
*/

void Ball::Move(float dt)
{
	rect.x += (moveSpeed * dt * moveDirection.x);
	rect.y += (moveSpeed * dt * moveDirection.y);
}
