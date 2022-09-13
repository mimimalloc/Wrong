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
	void FadeIn(float rate = 0.3f);
	void FadeOut(float rate = 0.3f);
private:
	void Update(float dt);
	void Draw();
	void DrawAlpha();
	void UpdateAlpha(float dt);

	std::deque<IScene*> scenes;

	bool fadingIn;
	bool fadingOut;
	float fadeAlpha;
	float fadeRate;
};

