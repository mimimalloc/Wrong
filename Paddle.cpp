#include "Paddle.h"

Paddle::Paddle(float x, float y, float defaultSpeed, Vector2 bounds, KeyboardKey upKey, KeyboardKey downKey):
	Entity(x, y, 20, 120, 1.0f),
	defaultSpeed(defaultSpeed), speed(defaultSpeed), bounds(bounds), defaultPos({x, y}),
	upKey(upKey), downKey(downKey)
{
}

void Paddle::Update(float dt)
{
	if (IsKeyDown(upKey)) {
		MoveUp(dt);
	}
	if (IsKeyDown(downKey)) {
		MoveDown(dt);
	}
}

void Paddle::Draw()
{
	DrawRectangleRec(rect, Fade(WHITE, opacity));
}

void Paddle::SpeedUp(float factor)
{
	speed *= factor;
}

void Paddle::ResetSpeed()
{
	speed = defaultSpeed;
}

void Paddle::ResetPos()
{
	rect.x = defaultPos.x;
	rect.y = defaultPos.y;
}

void Paddle::MoveUp(float dt)
{
	rect.y -= speed * dt;
	if (rect.y < bounds.x) {
		rect.y = bounds.x;
	}
}

void Paddle::MoveDown(float dt)
{
	rect.y += speed * dt;
	if (rect.y + rect.height > bounds.y) {
		rect.y = bounds.y - rect.height;
	}
}
