#pragma once
#include "EventSystem.h"
#include "Entity.h"

enum FadeDirection {
	fadeout,
	fadein
};

class FadeEvent : public Event
{
public:
	FadeEvent(Entity* entity, FadeDirection dir, float rate);
	void Start();
	void Run(float dt);
	void End() {}
private:
	Entity* fadeEntity;
	FadeDirection direction;
	float rate;
};

