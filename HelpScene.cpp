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
	Vector2 topLeft = game->Screen()->topLeft;
	Vector2 botRight = game->Screen()->botRight;

	DrawRectangle(topLeft.x + 8, topLeft.y + 8, botRight.x - 16, botRight.y - 16, BLACK);
	DrawRectangleLinesEx({ topLeft.x + 20, topLeft.y + 20, botRight.x - 40, botRight.y - 40 }, 4, WHITE);
	DrawTextEx(titleFont, "Wrong!", { topLeft.x + 60, topLeft.y + 40 }, 32, 16, WHITE);
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
		{ topLeft.x + 60, topLeft.y + 100 }, 18, 16, WHITE);
}
