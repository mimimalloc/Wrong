#include "Game.h"
#include "InitScene.h"

extern OverlayEntity* g_overlay;

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
	IScene* initScene = new InitScene(eventQueue, sceneManager);
	sceneManager->AddFrontScene(initScene);
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
	// The Game instance is responsible for drawing the overlay on top of the screen
	g_overlay->Draw();

	EndDrawing();
}
