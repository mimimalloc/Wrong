#include "TitleScene.h"
#include "raylib.h"
#include "FadeEvent.h"
#include "WaitEvent.h"
#include "SceneManager.h"
#include "SelectionMenu.h"
#include "GameScene.h"
#include "NewSceneEvent.h"

extern OverlayEntity* g_overlay;

TitleScene::TitleScene(EventQueue* eq, SceneManager* sm) :
	suppressUpdates(false), eventQueue(eq), sceneManager(sm), entityManager(new EntityManager())
{
	
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Font font = LoadFont("resources/RaccoonSerif-Bold.ttf");
	TextEntity* text = new TextEntity("WRONG!", 260, 120, 64, WHITE, 1.0f, font);

	entityManager->AddEntity("text", text);

	SelectionMenu* menu = new SelectionMenu("resources/RaccoonSerif-Monospace.ttf", 24, 32, 260, 240, 200, 32);
	menu->AddOption("New Game");
	menu->AddOption("Quit Game");

	entityManager->AddEntity("menu", menu);

	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.8f));
}

void TitleScene::Draw()
{
	entityManager->Draw();
}

SceneStatus TitleScene::Update(float dt)
{
	entityManager->Update(dt);

	// Selection menu is cast from an entity pointer to its specific pointer type
	SelectionMenu* menu = (SelectionMenu*)(entityManager->GetEntity("menu"));

	// Menu item selection (up/down)
	if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {	
		menu->Down();
	}
	else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
		menu->Up();
	}

	// Confirm menu item selection
	if (IsKeyReleased(KEY_ENTER) || IsKeyReleased(KEY_SPACE)) {
		if (menu->GetSelection() == 0) {
			entityManager->RemoveEntity("menu");
			eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.5f));

			GameScene* gameScene = new GameScene(eventQueue, sceneManager);
			eventQueue->QueueEvent(new NewSceneEvent(sceneManager, gameScene));
			eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 1.0f));
		} else {
			return EXIT_SIGNAL;
		}
	}
	
	return CONTINUE_UPDATES;
}
