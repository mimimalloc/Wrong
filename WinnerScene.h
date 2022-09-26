#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "SceneManager.h"
#include <string>
#include "EntityManager.h"

/**
	[ WinnerScene ]
	This scene occurs on top of the game scene
	when a player reaches a score of 10. It blocks
	the game scene from updating until it is finished.
*/
class WinnerScene : public IScene
{
public:
	WinnerScene(std::string winner, EventQueue* eq, SceneManager* sm);
	~WinnerScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();

private:
	// The font of the "winner" text
	Font font;
	// The winner of the game as a string
	std::string winner;
	// The main event queue
	EventQueue* eventQueue;
	// The main scene manager
	SceneManager* sceneManager;
	// This scene's entity manager
	EntityManager* entityManager;
};

