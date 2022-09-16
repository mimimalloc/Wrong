#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "OverlayEntity.h"
#include "SceneManager.h"
#include "TextEntity.h"

/**
	[ TitleScene ]
	A scene currently being used for testing purposes.
	Will eventually be used as a title screen for the game.
*/
class TitleScene : public IScene
{
public:
	TitleScene(EventQueue* eq, SceneManager* sm);
	~TitleScene();

	void Initialize();
	void Draw();
	bool Update(float dt);
private:
	bool suppressUpdates;
	// Pointer to the main event queue
	EventQueue* eventQueue;
	// Pointer to the main scene manager
	SceneManager* sceneManager;

	TextEntity* text;
};

