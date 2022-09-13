#include "TitleScene.h"
#include "raylib.h"

TitleScene::TitleScene() :
	suppressUpdates(false)
{
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
