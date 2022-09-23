#pragma once
#include "raylib.h"
#include "IScene.h"
#include <queue>
#include "EventSystem.h"
#include "SceneManager.h"

/**
	[ Game ]
	This class is fairly simple - it has pointer access to an EventQueue and SceneManager,
	and ensures that both run during the game loops - with the EventQueue running in the Update portion,
	and the SceneManager running in both the Update and Draw portions of the loop.

	In other words, it's more of a bootstrapper and facilitator than having much in the way of
	responsibilites of its own. But it does define certain behaviors (i.e. that its EventQueue 
	intentionally blocks SceneManager updates while it has events in it)
*/
class Game
{
public:
	Game();
	~Game();

	// Initialize is responsible for one-time setup of things like the window size and title.
	void Initialize();

	// Run executes the core game loop, divided into Update and Draw.
	// Update occurs first, and then Draw.
	void Run();

	// Exit will make whatever preparations for the application to close that
	// do not make sense to put in the destructor.
	void Exit();
private:
	// Update is the part of the Run loop that handles the game logic that occurs
	// underneath the hood. It takes a float representing the current delta time -
	// how much time has passed since the last frame, which is useful in making the game
	// behave with a consistent speed.
	void Update(float dt);

	// Draw is the part of the Run loop that handles how things are drawn to the screen.
	// It prepares the screen to draw, and then delegates drawing responsibility to the
	// SceneManager, which in turn delegates drawing to the active scenes.
	void Draw();

	// The Game object has access to an EventQueue that allows for special "Events" that
	// block other updates while they are active. See the EventSystem files for more information.
	EventQueue* eventQueue;

	// The Game object has access to a SceneManager that, as the name implies, manages the
	// active scenes to update and draw them. See the SceneManager files for more information.
	SceneManager* sceneManager;

	// This boolean is set to true when the game is shutting down and future Draw calls should
	// not be run
	bool isShuttingDown;

};

