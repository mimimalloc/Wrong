#include "InitScene.h"
#include "../Entities/OverlayEntity.h"

extern OverlayEntity* g_overlay;

InitScene::InitScene(Game* game):
	suppressUpdates(false), game(game),
	entityManager(new EntityManager())
{
	
}

InitScene::~InitScene()
{
	delete entityManager;
}

void InitScene::Initialize()
{
	float xpos = game->Screen()->topLeft.x + 48;
	float ypos = game->Screen()->topLeft.y + 80;

	Font font = LoadFont("resources/RaccoonSerif-Monospace.ttf");
	TextEntity* text1 = new TextEntity("Developed by", xpos, ypos, 24, WHITE, 1.0f, font);
	TextEntity* text2 = new TextEntity("Noemi Banks (mimimalloc)", xpos + 20, ypos + 40, 32, WHITE, 1.0f, font);

	ImageEntity* rayLogo = new ImageEntity("resources/raylib_96x96.png", 0, 0, 96, 96);
	rayLogo->SetPosCentered({ game->Screen()->botCenter.x, game->Screen()->botCenter.y - 240 });

	entityManager->AddEntity("text1", text1);
	entityManager->AddEntity("text2", text2);
	entityManager->AddEntity("logo", rayLogo);
	
	IScene* newScene = new TitleScene(game);

	auto events = game->Events();
	events->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.9f));
	events->QueueEvent(new WaitEvent(2));
	events->QueueEvent(new FadeEvent(g_overlay, fadein, 0.9f));
	events->QueueEvent(new NewSceneEvent(game->Scenes(), newScene));
}

SceneStatus InitScene::Update(float dt)
{
	entityManager->Update(dt);
	return CONTINUE_UPDATES;
}

void InitScene::Draw()
{
	entityManager->Draw();
}
