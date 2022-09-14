#pragma once
#include "EventSystem.h"
class WaitEvent : public Event
{
public:
	WaitEvent(float duration);
	void Start();
	void Run(float dt);
	void End() {}
private:
	float currentWaitTime;
	float targetWaitTime;
};
