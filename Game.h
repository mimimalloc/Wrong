#pragma once
#include "raylib.h"
#include "IScene.h"
#include <queue>
#include "EventSystem.h"


class Game
{
public:
	Game();
	~Game();

	void Initialize();
	void Run();
	void Exit();
	void ClearScenes();
private:
	void Update(float dt);
	void Draw();

	EventQueue* eventQueue;
	std::deque<IScene*> scenes;
};

