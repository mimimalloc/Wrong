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
#include "EntityManager.h"
#include "AudioManager.h"

class InitScene : public IScene
{
public:
	InitScene(EventQueue* eq, SceneManager* sm, AudioManager* am);
	~InitScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();
private:
	EventQueue* eventQueue;
	SceneManager* sceneManager;
	AudioManager* audioManager;
	EntityManager* entityManager;
	bool suppressUpdates;
};

