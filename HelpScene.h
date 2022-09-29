#pragma once
#include "IScene.h"
#include "raylib.h"
#include "EventSystem.h"

/**
	[ HelpScene ]
	A simple scene that displays
	instructions for how to play
	the game
*/
class HelpScene : public IScene
{
public:
	HelpScene(EventQueue* eventQueue);
	~HelpScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();
private:
	// Font of the game title
	Font titleFont;
	// Font of the help text
	Font textFont;
	// The main event queue
	EventQueue* eventQueue;
};

