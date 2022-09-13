#include "TitleScene.h"
#include "raylib.h"

TitleScene::TitleScene() :
	suppressUpdates(false),
	textAlpha(0.0f)
{
}

TitleScene::~TitleScene()
{
}

void TitleScene::Draw()
{
	DrawText("Hey, how're you doing?", 20, 20, 18, Fade(WHITE, textAlpha));
}

bool TitleScene::Update(float dt)
{
	if (textAlpha < 1.0f) {
		textAlpha += 0.2 * dt;
	}
	return suppressUpdates;
}
