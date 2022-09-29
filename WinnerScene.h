#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "SceneManager.h"
#include <string>
#include "EntityManager.h"
#include "AudioManager.h"
#include "Game.h"

/**
	[ WinnerScene ]
	This scene occurs on top of the game scene
	when a player reaches a score of 10. It blocks
	the game scene from updating until it is finished.
*/
class WinnerScene : public IScene
{
public:
	WinnerScene(std::string winner, Game* game);
	~WinnerScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();

private:
	// The font of the "winner" text
	Font font;
	// The winner of the game as a string
	std::string winner;
	// Pointer to the game object
	Game* game;
	// This scene's entity manager
	EntityManager* entityManager;
};

