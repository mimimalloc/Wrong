#pragma once
#include "EventSystem.h"

/**
	[ WaitEvent ]
	This event does one thing and one thing only - waits for a duration
	in approximate seconds before finishing.
*/
class WaitEvent : public Event
{
public:
	WaitEvent(float duration);
	void Start();
	void Run(float dt);
	void End() {}
private:
	// How long the event has been active
	float currentWaitTime;

	// The target amount of time, after which the event will be finished
	float targetWaitTime;
};
