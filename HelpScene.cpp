#include "HelpScene.h"
#include "WaitEvent.h"

HelpScene::HelpScene(Game* game):
	game(game)
{
	titleFont = LoadFont("resources/RaccoonSerif-Bold.ttf");
	textFont = LoadFont("resources/RaccoonSerif-Monospace.ttf");
}

HelpScene::~HelpScene()
{
}

void HelpScene::Initialize()
{
}

SceneStatus HelpScene::Update(float dt)
{
	if (IsKeyDown(KEY_ENTER) || IsKeyDown(KEY_SPACE)) {
		game->Events()->QueueEvent(new WaitEvent(0.25));
		return END_SCENE;
	}
	return STOP_UPDATES;
}

void HelpScene::Draw()
{
	DrawRectangle(20, 20, 760, 560, BLACK);
	DrawRectangleLinesEx({ 40, 40, 720, 520 }, 4, WHITE);
	DrawTextEx(titleFont, "Wrong!", { 80, 60 }, 32, 16, WHITE);
	DrawTextEx(textFont, 
		"In this game, you must\n"
		"AVOID hitting the ball\n"
		"with your paddle.\n"
		"Every time the ball\n"
		"hits your paddle, your\n"
		"opponent will score!\n\n"
		"CONTROLS:\n"
		" Player 1:\n"
		"  W - Up\n"
		"  S - Down\n"
		" Player 2:\n"
		"  Up Arrow - Up\n" 
		"  Down Arrow - Down\n\n\n"
		" -Press ENTER or SPACE-",
		{ 80, 120 }, 16, 16, WHITE);
}
