#include "WaitEvent.h"

WaitEvent::WaitEvent(float duration):
	currentWaitTime(0.0f), targetWaitTime(duration)
{
}

void WaitEvent::Start()
{
	isRunning = true;
}

void WaitEvent::RunUpdate(float dt)
{
	currentWaitTime += dt;

	if (currentWaitTime >= targetWaitTime) {
		isRunning = false;
		isFinished = true;
	}
}
