#include "TitleScene.h"
#include "raylib.h"
#include "FadeEvent.h"
#include "WaitEvent.h"
#include "SceneManager.h"

extern OverlayEntity* g_overlay;

TitleScene::TitleScene(EventQueue* eq, SceneManager* sm) :
	suppressUpdates(false), eventQueue(eq), sceneManager(sm)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	// Testing the EventQueue
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadeout, 0.2f));
	eventQueue->QueueEvent(new WaitEvent(5));
	eventQueue->QueueEvent(new FadeEvent(g_overlay, fadein, 0.2f));
}

void TitleScene::Draw()
{
	DrawText("Hey, how're you doing?", 20, 20, 18, WHITE);
}

bool TitleScene::Update(float dt)
{
	return suppressUpdates;
}
