#include "TitleScene.h"
#include "raylib.h"
#include "FadeEvent.h"
#include "WaitEvent.h"

TitleScene::TitleScene(EventQueue* eq) :
	suppressUpdates(false), eventQueue(eq),
	overlay(new OverlayEntity())
{
	// Testing the EventQueue
	eventQueue->QueueEvent(new FadeEvent(overlay, fadeout, 0.2f));
	eventQueue->QueueEvent(new WaitEvent(5));
	eventQueue->QueueEvent(new FadeEvent(overlay, fadein, 0.2f));
}

TitleScene::~TitleScene()
{
	delete overlay;
}

void TitleScene::Draw()
{
	DrawText("Hey, how're you doing?", 20, 20, 18, WHITE);
	overlay->Draw();
}

bool TitleScene::Update(float dt)
{
	return suppressUpdates;
}
