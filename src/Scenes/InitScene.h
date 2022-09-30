#pragma once
#include "raylib.h"
#include "IScene.h"
#include "TitleScene.h"
#include "../Events/EventSystem.h"
#include "../Events/FadeEvent.h"
#include "../Events/WaitEvent.h"
#include "../Events/NewSceneEvent.h"
#include "../Entities/TextEntity.h"
#include "../Entities/ImageEntity.h"
#include "../Entities/EntityManager.h"
#include "../Game.h"

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

