#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "raylib.h"
#include "OverlayEntity.h"
#include "FadeEvent.h"
#include "WaitEvent.h"
#include "NewSceneEvent.h"
#include "TitleScene.h"

class InitScene : public IScene
{
public:
	InitScene(EventQueue* eq, SceneManager* sm);

	void Initialize();
	bool Update(float dt);
	void Draw();
private:
	EventQueue* eventQueue;
	SceneManager* sceneManager;
	bool suppressUpdates;
};

