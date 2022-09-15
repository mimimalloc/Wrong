#pragma once
#include "EventSystem.h"
#include "Entity.h"

/**
	[ FadeDirection ]
	Determines whether the transition increases or
	decreases an Entity's opacity
*/
enum FadeDirection {
	fadeout,
	fadein
};


/**
	[ FadeEvent]
	This is an event that stores a pointer to an Entity,
	a direction to fade opacity in or out, and the rate at
	which to increase or decrease the opacity of the Entity
	each iteration of the game loop.
*/
class FadeEvent : public Event
{
public:
	FadeEvent(Entity* entity, FadeDirection dir, float rate);
	void Start();
	void Run(float dt);
	void End() {}
private:
	// Pointer to the Entity being acted upon
	Entity* fadeEntity;

	// Whether the Entity is "faded" in or out
	FadeDirection direction;

	// The rate at which the Entity fades
	float rate;
};

