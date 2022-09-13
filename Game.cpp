#include "Game.h"
#include "TitleScene.h"

Game::Game()
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

void Game::Update(float dt)
{
	for (IScene* scene : scenes) {
		if (scene->Update(dt)) {
			break;
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

	EndDrawing();
}
