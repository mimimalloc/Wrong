#pragma once
#include "IScene.h"
#include "raylib.h"
#include "EventSystem.h"
#include "Game.h"

/**
	[ HelpScene ]
	A simple scene that displays
	instructions for how to play
	the game
*/
class HelpScene : public IScene
{
public:
	HelpScene(Game* game);
	~HelpScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();
private:
	// Font of the game title
	Font titleFont;
	// Font of the help text
	Font textFont;
	// Pointer to the game object
	Game* game;
};

