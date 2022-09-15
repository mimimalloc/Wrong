#pragma once
#include "raylib.h"
#include "IScene.h"
#include <queue>
#include "EventSystem.h"
#include "SceneManager.h"


class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Run();
	void Exit();
private:
	void Update(float dt);
	void Draw();

	EventQueue* eventQueue;
	SceneManager* sceneManager;
};

