#pragma once
#include "raylib.h"
#include "IScene.h"
#include <queue>

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
	std::deque<IScene*> scenes;
};

