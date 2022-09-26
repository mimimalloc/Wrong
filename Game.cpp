#include "Game.h"
#include "InitScene.h"
#include "GameScene.h"

extern OverlayEntity* g_overlay;

Game::Game() :
	eventQueue(new EventQueue()),
	sceneManager(new SceneManager()),
	isShuttingDown(false)
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
	
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.5f));
}

void Game::Run()
{
	while (!WindowShouldClose() && !isShuttingDown) {
		Update(GetFrameTime());
		if (!isShuttingDown) {
			Draw();
		}
	}
	Exit();
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

	// If the scene manager's Update returns true, that means an exit signal
	// from a scene has been passed
	if (sceneManager->Update(dt)) {
		isShuttingDown = true;
	}
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
