#include "Game.h"
#include "TitleScene.h"

Game::Game() :
	eventQueue(new EventQueue())
{
}

Game::~Game()
{
	ClearScenes();
	delete eventQueue;
}

void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 600, "Wrong!");
	
	IScene* title = new TitleScene(eventQueue);
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

void Game::ClearScenes()
{
	for (auto pointer : scenes) {
		delete pointer;
	}
	scenes.clear();
}

void Game::Update(float dt)
{
	// Active events will block scene updates until the event queue is empty
	if (eventQueue->HasEvents()) {
		eventQueue->Update(dt);
		return;
	}

	for (IScene* scene : scenes) {
		// Updates end if a scene's update returns true - meaning the scene is "blocking"
		if (scene->Update(dt)) { break; }
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
