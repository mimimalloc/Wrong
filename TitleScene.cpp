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

TitleScene::TitleScene(Game* game) :
	suppressUpdates(false), game(game),
	entityManager(new EntityManager())
{
	
}

TitleScene::~TitleScene()
{
	delete entityManager;
}

void TitleScene::Initialize()
{
	auto audio = game->Audio();

	float titleX = game->Screen()->topCenter.x - 160;
	float titleY = game->Screen()->topCenter.y + 128;
	Font font = LoadFont("resources/RaccoonSerif-Bold.ttf");
	TextEntity* text = new TextEntity("WRONG!", titleX, titleY, 64, WHITE, 1.0f, font);

	entityManager->AddEntity("text", text);

	audio->AMLoadMusic("title", "resources/titleloop.mp3");
	audio->AMPlayMusic("title");

	SelectionMenu* menu = new SelectionMenu("resources/RaccoonSerif-Monospace.ttf", 24, 32, 0, 0, 200, 32);
	menu->AddOption("New Game");
	menu->AddOption("Instructions");
	menu->AddOption("Quit Game");

	menu->SetPosCentered(game->Screen()->midCenter);

	entityManager->AddEntity("menu", menu);

	game->Events()->QueueEvent(new FadeEvent(g_overlay, fadeout, 1.5f));
}

void TitleScene::Draw()
{
	entityManager->Draw();
}

SceneStatus TitleScene::Update(float dt)
{
	auto audio = game->Audio();
	auto events = game->Events();
	auto scenes = game->Scenes();

	audio->AMUpdateMusicStream("title");
	entityManager->Update(dt);

	// Selection menu is cast from an entity pointer to its specific pointer type
	SelectionMenu* menu = (SelectionMenu*)entityManager->GetEntity("menu");

	// Menu item selection (up/down)
	if (IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S)) {
		audio->AMPlaySound("select");
		menu->Down();
	}
	else if (IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W)) {
		audio->AMPlaySound("select");
		menu->Up();
	}

	// Confirm menu item selection
	if (IsKeyReleased(KEY_ENTER) || IsKeyReleased(KEY_SPACE)) {
		audio->AMPlaySound("choice");
		if (menu->GetSelection() == 0) {
			audio->AMUnloadMusic("title");
			entityManager->RemoveEntity("menu");
			events->QueueEvent(new FadeEvent(g_overlay, fadein, 0.5f));

			GameScene* gameScene = new GameScene(game);
			events->QueueEvent(new NewSceneEvent(game->Scenes(), gameScene));
			events->QueueEvent(new FadeEvent(g_overlay, fadeout, 1.0f));
		
		}
		else if (menu->GetSelection() == 1) {
			HelpScene* helpScene = new HelpScene(game);

			scenes->AddFrontScene(helpScene);
		} else {
			return EXIT_SIGNAL;
		}
	}
	
	return CONTINUE_UPDATES;
}
