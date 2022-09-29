#include "TitleScene.h"
#include "raylib.h"
#include "FadeEvent.h"
#include "WaitEvent.h"
#include "SceneManager.h"
#include "SelectionMenu.h"
#include "GameScene.h"
#include "NewSceneEvent.h"
#include "HelpScene.h"

extern OverlayEntity* g_overlay;

TitleScene::TitleScene(EventQueue* eq, SceneManager* sm, AudioManager* am) :
	suppressUpdates(false), eventQueue(eq), sceneManager(sm), audioManager(am),
	entityManager(new EntityManager())
{
	
}

TitleScene::~TitleScene()
{
	delete entityManager;
}

void TitleScene::Initialize()
{
	Font font = LoadFont("resources/RaccoonSerif-Bold.ttf");
	TextEntity* text = new TextEntity("WRONG!", 260, 120, 64, WHITE, 1.0f, font);

	entityManager->AddEntity("text", text);

	audioManager->AMLoadMusic("title", "resources/titleloop.mp3");
	audioManager->AMPlayMusic("title");

	SelectionMenu* menu = new SelectionMenu("resources/RaccoonSerif-Monospace.ttf", 24, 32, 260, 240, 200, 32);
	menu->AddOption("New Game");
	menu->AddOption("Instructions");
	menu->AddOption("Quit Game");

	entityManager->AddEntity("menu", menu);

	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 1.5f));
}

void TitleScene::Draw()
{
	entityManager->Draw();
}

SceneStatus TitleScene::Update(float dt)
{
	audioManager->AMUpdateMusicStream("title");
	entityManager->Update(dt);

	// Selection menu is cast from an entity pointer to its specific pointer type
	SelectionMenu* menu = (SelectionMenu*)entityManager->GetEntity("menu");

	// Menu item selection (up/down)
	if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
		audioManager->AMPlaySound("select");
		menu->Down();
	}
	else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
		audioManager->AMPlaySound("select");
		menu->Up();
	}

	// Confirm menu item selection
	if (IsKeyReleased(KEY_ENTER) || IsKeyReleased(KEY_SPACE)) {
		audioManager->AMPlaySound("choice");
		if (menu->GetSelection() == 0) {
			audioManager->AMUnloadMusic("title");
			entityManager->RemoveEntity("menu");
			eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.5f));

			GameScene* gameScene = new GameScene(eventQueue, sceneManager, audioManager);
			eventQueue->QueueEvent(new NewSceneEvent(sceneManager, gameScene));
			eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 1.0f));
		
		}
		else if (menu->GetSelection() == 1) {
			HelpScene* helpScene = new HelpScene(eventQueue);

			sceneManager->AddFrontScene(helpScene);
		} else {
			return EXIT_SIGNAL;
		}
	}
	
	return CONTINUE_UPDATES;
}
