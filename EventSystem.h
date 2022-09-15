#pragma once
#include <queue>

/**
	[ Event ]
	An event can be understood as Something That Happens, that
	is considered significant enough that other Things That Happen 
	won't Happen until the event has finished and leaves the EventQueue.

	This is a base class, intended to be inherited by more specific
	Event classes.
*/
class Event
{
protected:
	// The event is "running" if this boolean is true
	bool isRunning{ false };
	// The event has finished what it was supposed to do if this boolean is true
	bool isFinished{ false };
public:
	virtual ~Event() {}

	// Start methods determine what the event will do when it first reaches the top
	// of an EventQueue
	virtual void Start() = 0;

	// Run methods determine what the event does each update cycle
	virtual void Run(float dt) = 0;

	// End methods determine what the event does before it leaves the EventQueue and is
	// destroyed
	virtual void End() = 0;

	// Returns whether the event is running/finished
	bool IsRunning() { return isRunning; }
	bool IsFinished() { return isFinished; }
};

/**
	[ EventQueue ]
	An EventQueue stores events and executes them in the order
	they are queued. 
	
	If there is no currentEvent and there are events in the queue, 
	the first event is retrieved, popped from the queue, and becomes
	the new currentEvent.

	When the currentEvent is "finished", it is destroyed and the
	currentEvent points to nullptr until another event is retrieved.

	Think of it like a jukebox: a CD is pulled from the queue and played,
	everyone dances the Audrey Horne dance, and then when the song's over, 
	the CD explodes and it's on to the next one. That's how jukeboxes work,
	right?
*/
class EventQueue
{
public:
	EventQueue();
	~EventQueue();

	// The EventQueue's update does four things: If there is no currentEvent but there is
	// one in the queue, it pops that item into currentEvent. If both currentEvent and the
	// queue are empty, it returns and does not continue. If the current event is running, it
	// gets updated. And if the current event is finished, EndEvent removes it
	void Update(float dt);

	// An event gets queued into the eQueue, where it will become the currentEvent once
	// it reaches the front of the queue and the last currentEvent has finished
	void QueueEvent(Event* event);

	// The queue is cleared and the memory pointed to by each Event pointer is freed
	void ClearQueue();

	// Returns true if there is a currentEvent and/or events left in the queue
	bool HasEvents();
private:
	// Points to the current event being run
	Event* currentEvent{ nullptr };

	// A standard library queue holds the Event pointers
	std::queue<Event*> eQueue;

	// The next event is retrieved and removed from the queue, and
	// its Start method is run.
	void StartNextEvent();

	// The currentEvent's End method is run, then its memory is freed
	// and the pointer is set to nullptr.
	void EndEvent();
};

