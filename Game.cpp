#include "Game.h"
#include "TitleScene.h"

Game::Game() :
	eventQueue(new EventQueue()),
	sceneManager(new SceneManager())
{
}

Game::~Game()
{
	delete sceneManager;
	delete eventQueue;
}

void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(800, 600, "Wrong!");
	
	// Add a new scene to the scene manager to start the game proper
	IScene* title = new TitleScene(eventQueue);
	sceneManager->AddFrontScene(title);
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
	// Active events will block scene updates until the event queue is empty
	if (eventQueue->HasEvents()) {
		eventQueue->Update(dt);
		return;
	}

	sceneManager->Update(dt);
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	sceneManager->Draw();

	EndDrawing();
}
