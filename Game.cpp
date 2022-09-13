#include "Game.h"
#include "TitleScene.h"

Game::Game():
	fadingIn(true), fadingOut(false), fadeAlpha(1.0f), fadeRate(0.3f)
{
}

Game::~Game()
{
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

void Game::FadeIn(float rate)
{
	fadingOut = false;
	fadingIn = true;
	fadeRate = rate;
}

void Game::FadeOut(float rate)
{
	fadingIn = false;
	fadingOut = true;
	fadeRate = rate;
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
		}
		else {
			fadeAlpha -= fadeRate * dt;
		}
	}

	if (fadingOut) {
		if (fadeAlpha >= 1.0f) {
			fadeAlpha = 1.0f;
			fadingOut = false;
		}
		else {
			fadeAlpha += fadeRate * dt;
		}
	}
}
