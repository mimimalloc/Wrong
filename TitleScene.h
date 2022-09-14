#pragma once
#include "IScene.h"
#include "EventSystem.h"

class TitleScene : public IScene
{
public:
	TitleScene(EventQueue* eq);
	~TitleScene();

	void Draw();
	bool Update(float dt);
private:
	bool suppressUpdates;
	EventQueue* eventQueue;
};

