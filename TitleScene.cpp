#include "TitleScene.h"
#include "raylib.h"
#include "FadeEvent.h"

TitleScene::TitleScene(EventQueue* eq) :
	suppressUpdates(false), eventQueue(eq)
{
	eventQueue->QueueEvent(new FadeEvent(fadein, 0.3f));
}

TitleScene::~TitleScene()
{
}

void TitleScene::Draw()
{
	DrawText("Hey, how're you doing?", 20, 20, 18, WHITE);
}

bool TitleScene::Update(float dt)
{
	return suppressUpdates;
}
