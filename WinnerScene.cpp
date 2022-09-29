#include "WinnerScene.h"
#include "SelectionMenu.h"
#include "HelpScene.h"
#include "WaitEvent.h"

WinnerScene::WinnerScene(std::string winner, EventQueue* eq, SceneManager* sm):
	winner(winner), eventQueue(eq), sceneManager(sm),
	entityManager(new EntityManager())
{
	font = LoadFont("resources/RaccoonSerif-Bold.ttf");
}

WinnerScene::~WinnerScene()
{
	delete entityManager;
}

void WinnerScene::Initialize()
{
	SelectionMenu* playAgainMenu = new SelectionMenu("resources/RaccoonSerif-Monospace.ttf", 32, 48, 140, 240, 300, 48);
	playAgainMenu->AddOption("Play Again");
	playAgainMenu->AddOption("Instructions");
	playAgainMenu->AddOption("Exit Game");

	entityManager->AddEntity("menu", playAgainMenu);
}

SceneStatus WinnerScene::Update(float dt)
{
	auto menu = (SelectionMenu*)entityManager->GetEntity("menu");

	if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
		menu->Down();
	}

	if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
		menu->Up();
	}

	if (IsKeyPressed(KEY_ENTER) || IsKeyPressed(KEY_SPACE)) {
		HelpScene* helpScene;
		switch (menu->GetSelection()) {
		case 0:
			return END_SCENE;
		case 1:
			helpScene = new HelpScene(eventQueue);
			sceneManager->AddFrontScene(helpScene);
			eventQueue->QueueEvent(new WaitEvent(0.25));
			return STOP_UPDATES;
		default:
			return EXIT_SIGNAL;
		}
	}

	entityManager->Update(dt);
	return STOP_UPDATES;
}

void WinnerScene::Draw()
{
	DrawRectangle(100, 100, 600, 300, BLACK);
	DrawRectangleLinesEx(Rectangle{ 120, 120, 560, 280 }, 8, WHITE);

	DrawText((winner + " has won!").c_str(), 140, 140, 48, WHITE);
	entityManager->Draw();
}
