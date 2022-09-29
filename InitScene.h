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
#include "Game.h"

class InitScene : public IScene
{
public:
	InitScene(Game* game);
	~InitScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();
private:
	Game* game;
	EntityManager* entityManager;
	bool suppressUpdates;
};

