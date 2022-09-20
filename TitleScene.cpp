#include "TitleScene.h"
#include "raylib.h"
#include "FadeEvent.h"
#include "WaitEvent.h"
#include "SceneManager.h"

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

	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.4f));
	eventQueue->QueueEvent(new WaitEvent(5));
}

void TitleScene::Draw()
{
	entityManager->Draw();
}

bool TitleScene::Update(float dt)
{
	entityManager->Update(dt);
	return suppressUpdates;
}
