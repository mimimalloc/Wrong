#pragma once
#include "IScene.h"
#include "OverlayEntity.h"
#include "TextEntity.h"
#include "EntityManager.h"
#include "Game.h"

/**
	[ TitleScene ]
	A scene currently being used for testing purposes.
	Will eventually be used as a title screen for the game.
*/
class TitleScene : public IScene
{
public:
	TitleScene(Game* game);
	~TitleScene();

	void Initialize();
	void Draw();
	SceneStatus Update(float dt);
private:
	bool suppressUpdates;
	// Pointer to the game object
	Game* game;
	// Pointer to the scene's entity manager
	EntityManager* entityManager;
};

