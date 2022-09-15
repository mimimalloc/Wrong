#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "OverlayEntity.h"

/**
	[ TitleScene ]
	A scene currently being used for testing purposes.
	Will eventually be used as a title screen for the game.
*/
class TitleScene : public IScene
{
public:
	TitleScene(EventQueue* eq);
	~TitleScene();

	void Draw();
	bool Update(float dt);
private:
	bool suppressUpdates;
	// Pointer to the main event queue
	EventQueue* eventQueue;

	// An overlay that covers and obscures the screen until it
	// is faded out
	OverlayEntity* overlay;
};

