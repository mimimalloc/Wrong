#include "Game.h"
#include "InitScene.h"
#include "GameScene.h"

extern OverlayEntity* g_overlay;

const int GAME_WIDTH = 800;
const int GAME_HEIGHT = 600;

Game::Game() :
	events(new EventQueue()),
	scenes(new SceneManager()),
	audio(new AudioManager()),
	isShuttingDown(false)
{
	float hCenter = GAME_WIDTH / 2;
	float vCenter = GAME_HEIGHT / 2;
	winPoints = {
		{ 0, 0 }, { hCenter, 0 }, { GAME_WIDTH, 0 },
		{ 0, vCenter }, { hCenter, vCenter }, { GAME_WIDTH, vCenter },
		{ 0, GAME_HEIGHT }, { hCenter, GAME_HEIGHT }, { GAME_WIDTH, GAME_HEIGHT }
	};
}

Game::~Game()
{
	delete scenes;
	delete events;
	delete audio;
}

void Game::Initialize()
{
	SetTargetFPS(60);
	InitWindow(GAME_WIDTH, GAME_HEIGHT, "Wrong!");

	// Activate audio manager and load universal sounds
	audio->AMActivate();
	audio->AMLoadSFX("select", "resources/select.wav");
	audio->AMLoadSFX("choice", "resources/choice.wav");
	audio->AMLoadSFX("ready", "resources/ready.wav");
	audio->AMLoadSFX("bounce", "resources/bounce.wav");
	audio->AMLoadSFX("goal", "resources/nope.wav");
	
	// Add a new scene to the scene manager to start the game proper
	IScene* initScene = new InitScene(this);
	scenes->AddFrontScene(initScene);
	
	events->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.5f));
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
	if (events->HasEvents()) {
		events->Update(dt);
		return;
	}

	// If the scene manager's Update returns true, that means an exit signal
	// from a scene has been passed
	if (scenes->Update(dt)) {
		isShuttingDown = true;
	}
}

void Game::Draw()
{
	BeginDrawing();
	ClearBackground(BLACK);

	scenes->Draw();
	// The Game instance is responsible for drawing the overlay on top of the screen
	g_overlay->Draw();

	EndDrawing();
}
