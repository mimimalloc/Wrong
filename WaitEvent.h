#pragma once
#include "EventSystem.h"
class WaitEvent : public Event
{
public:
	WaitEvent(float duration);
	void Start();
	void RunUpdate(float dt);
	void RunDraw() {}
	void End() {}
private:
	float currentWaitTime;
	float targetWaitTime;
};
