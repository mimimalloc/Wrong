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
	Font font = LoadFont("resources/Charcoal.ttf");
	TextEntity* text = new TextEntity("WRONG!", 320, 240, 64, WHITE, 1.0f, font);

	entityManager->AddEntity("text", text);

	// Testing the EventQueue
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.2f));
	eventQueue->QueueEvent(new WaitEvent(5));
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.2f));
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
