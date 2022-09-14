#pragma once
#include "EventSystem.h"

enum FadeDirection {
	fadeout,
	fadein
};

class FadeEvent : public Event
{
public:
	FadeEvent(FadeDirection dir, float rate);
	void Start();
	void RunUpdate(float dt);
	void RunDraw();
	void End() {}
private:
	FadeDirection direction;
	float rate;
	float opacity;
};

