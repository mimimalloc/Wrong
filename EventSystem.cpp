#include "EventSystem.h"

EventQueue::EventQueue()
{
}

EventQueue::~EventQueue()
{
	ClearQueue();
}

void EventQueue::Update(float dt)
{
	// If there is no current event and there is one in the queue, start the next event
	// Currently returns, meaning event isn't updated until next cycle
	if (currentEvent == nullptr && eQueue.size() > 0) {
		StartNextEvent();
		return;
	}
	// If the current event is null and there is nothing in the queue, don't continue
	else if (currentEvent == nullptr) {
		return;
	}

	// If the current event is running, update it
	if (currentEvent->IsRunning()) {
		currentEvent->Run(dt);
	}

	// If the current event is finished, end it
	if (currentEvent->IsFinished()) {
		EndEvent();
	}
}

void EventQueue::QueueEvent(Event* event)
{
	eQueue.push(event);
}

void EventQueue::ClearQueue()
{
	// Release memory at currentEvent if it's pointing to an event
	if (currentEvent != nullptr) {
		delete currentEvent;
	}

	// Release the memory of all entries in the queue
	while (eQueue.size() > 0) {
		delete eQueue.front();
		eQueue.pop();
	}
}

bool EventQueue::HasEvents()
{
	return (currentEvent != nullptr || eQueue.size() > 0);
}

void EventQueue::StartNextEvent()
{
	currentEvent = eQueue.front();
	eQueue.pop();
	currentEvent->Start();
}

void EventQueue::EndEvent()
{
	currentEvent->End();
	delete currentEvent;
	currentEvent = nullptr;
}