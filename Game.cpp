#include "Game.h"
#include "InitScene.h"
#include "GameScene.h"

extern OverlayEntity* g_overlay;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

Game::Game() :
	eventQueue(new EventQueue()),
	sceneManager(new SceneManager()),
	audioManager(new AudioManager()),
	isShuttingDown(false)
{
	winPoints = {};
	SetWinPoints();
}

Game::~Game()
{
	delete sceneManager;
	delete eventQueue;
	delete audioManager;
}

void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Wrong!");

	// Activate audio manager and load universal sounds
	audioManager->AMActivate();
	audioManager->AMLoadSFX("select", "resources/select.wav");
	audioManager->AMLoadSFX("choice", "resources/choice.wav");
	audioManager->AMLoadSFX("ready", "resources/ready.wav");
	audioManager->AMLoadSFX("bounce", "resources/bounce.wav");
	audioManager->AMLoadSFX("goal", "resources/nope.wav");
	
	// Add a new scene to the scene manager to start the game proper
	IScene* initScene = new InitScene(this);
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

void Game::SetWinPoints()
{
	float cx = SCREEN_WIDTH / 2;
	float cy = SCREEN_HEIGHT / 2;

	winPoints.topLeft = Vector2{ 0, 0 };
	winPoints.topCenter = Vector2{ cx, 0 };
	winPoints.topRight = Vector2{ SCREEN_WIDTH, 0 };
	winPoints.midLeft = Vector2{ 0, cy };
	winPoints.midCenter = Vector2{ cx, cy };
	winPoints.midRight = Vector2{ SCREEN_WIDTH, cy };
	winPoints.botLeft = Vector2{ 0, SCREEN_HEIGHT };
	winPoints.botCenter = Vector2{ cx, SCREEN_HEIGHT };
	winPoints.botRight = Vector2{ SCREEN_WIDTH, SCREEN_HEIGHT };
}
