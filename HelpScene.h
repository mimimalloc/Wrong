#pragma once
#include "IScene.h"
#include "raylib.h"
#include "EventSystem.h"

class HelpScene : public IScene
{
public:
	HelpScene(EventQueue* eventQueue);
	~HelpScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();
private:
	Font titleFont;
	Font textFont;
	EventQueue* eventQueue;
};

