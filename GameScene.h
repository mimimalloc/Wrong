#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "SceneManager.h"
#include "EntityManager.h"
#include "raylib.h"
class GameScene : public IScene
{
public:
	GameScene(EventQueue* eventQueue, SceneManager* sceneManager);
	~GameScene();

	void Initialize();
	void Draw();
	bool Update(float dt);
private:
	bool suppressUpdates;
	EventQueue* eventQueue;
	SceneManager* sceneManager;
	EntityManager* entityManager;
};

