#include "Game.h"
#include "TitleScene.h"

Game::Game():
	fadingIn(true), fadingOut(false), 
	fadeAlpha(1.0f), fadeRate(0.4f)
{

}

Game::~Game()
{
	ClearScenes();
}

void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 600, "Wrong!");
	
	IScene* title = new TitleScene();
	scenes.push_front(title);
}

void Game::Run()
{
	while (!WindowShouldClose()) {
		Update(GetFrameTime());
		Draw();
	}
}

void Game::Exit()
{
	CloseWindow();
}

void Game::FadeIn(std::function<void()> callback, float rate)
{
	fadingOut = false;
	fadingIn = true;
	fadeRate = rate;
	fadeCallback = callback;
}

void Game::FadeOut(std::function<void()> callback, float rate)
{
	fadingIn = false;
	fadingOut = true;
	fadeRate = rate;
	fadeCallback = callback;
}

void Game::ClearScenes()
{
	for (auto pointer : scenes) {
		delete pointer;
	}
	scenes.clear();
}

void Game::Update(float dt)
{
	// Scenes don't update if the game is fading in or out
	if (fadingIn || fadingOut) {
		UpdateAlpha(dt);
	}
	else {
		for (IScene* scene : scenes) {
			// Updates end if a scene's update returns true - meaning the scene is "blocking"
			if (scene->Update(dt)) { break; }
		}
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	for (IScene* scene : scenes) {
		scene->Draw();
	}

	DrawAlpha();

	EndDrawing();
}

void Game::DrawAlpha()
{
	DrawRectangle(0, 0, 800, 600, Fade(BLACK, fadeAlpha));
}

void Game::UpdateAlpha(float dt)
{
	if (fadingIn) {
		if (fadeAlpha <= 0.0f) {
			fadeAlpha = 0.0f;
			fadingIn = false;
			// Run and reset the stored fadeCallback lambda
			fadeCallback();
			fadeCallback = []() -> void {};
		}
		else {
			fadeAlpha -= fadeRate * dt;
		}
	}

	if (fadingOut) {
		if (fadeAlpha >= 1.0f) {
			fadeAlpha = 1.0f;
			fadingOut = false;
			// Run and reset the stored fadeCallback lambda
			fadeCallback();
			fadeCallback = []() -> void {};
		}
		else {
			fadeAlpha += fadeRate * dt;
		}
	}
}
