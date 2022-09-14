#include "FadeEvent.h"
#include "raylib.h"

FadeEvent::FadeEvent(FadeDirection dir, float rate) :
	direction(dir), rate(rate)
{
	if (direction == fadeout) {
		opacity = 0.0f;
	}
	else {
		opacity = 1.0f;
	}
}

void FadeEvent::Start()
{
	isRunning = true;
}

void FadeEvent::RunUpdate(float dt)
{
	if (direction == fadeout) {
		opacity += rate * dt;
		if (opacity >= 1.0f) {
			opacity = 1.0f;
			isRunning = false;
			isFinished = true;
		}
	} else {
		opacity -= rate * dt;
		if (opacity <= 0.0f) {
			opacity = 0.0f;
			isRunning = false;
			isFinished = true;
		}
	}
}

void FadeEvent::RunDraw()
{
	DrawRectangle(0, 0, 800, 600, Fade(BLACK, opacity));
}
