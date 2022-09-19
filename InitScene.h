#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "raylib.h"
#include "OverlayEntity.h"
#include "FadeEvent.h"
#include "WaitEvent.h"
#include "NewSceneEvent.h"
#include "TitleScene.h"
#include "TextEntity.h"
#include "ImageEntity.h"

class InitScene : public IScene
{
public:
	InitScene(EventQueue* eq, SceneManager* sm);
	~InitScene();

	void Initialize();
	bool Update(float dt);
	void Draw();
private:
	EventQueue* eventQueue;
	SceneManager* sceneManager;
	TextEntity* text;
	ImageEntity* image;
	bool suppressUpdates;
};

