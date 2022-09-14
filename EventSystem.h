#pragma once
#include <queue>

class Event
{
protected:
	bool isRunning{ false };
	bool isFinished{ false };
public:
	virtual ~Event() {}

	virtual void Start() = 0;
	virtual void Run(float dt) = 0;
	virtual void End() = 0;

	bool IsRunning() { return isRunning; }
	bool IsFinished() { return isFinished; }
};

class EventQueue
{
public:
	EventQueue();
	~EventQueue();

	void Update(float dt);
	void QueueEvent(Event* event);
	void ClearQueue();
	bool HasEvents();
private:
	Event* currentEvent{ nullptr };
	std::queue<Event*> eQueue;
	void StartNextEvent();
	void EndEvent();
};

