#include "GameScene.h"
#include "Paddle.h"
#include "WinnerScene.h"

GameScene::GameScene(Game* game):
	suppressUpdates(false), game(game),
	entityManager(new EntityManager()),
	wall(Rectangle { 0, 0, 800, 600 })
{
}

GameScene::~GameScene()
{
	delete entityManager;
}

void GameScene::Initialize()
{
	auto audio = game->Audio();

	audio->AMLoadMusic("game", "resources/gameloop.mp3");
	audio->AMPlayMusic("game");

	Scoreboard* scoreboard = new Scoreboard();
	entityManager->AddEntity("scoreboard", scoreboard);
	audio->AMPlaySound("ready");
	scoreboard->ReadyUp();

	Ball* ball = new Ball(150.0);
	entityManager->AddEntity("ball", ball);

	Vector2 ybounds{ 0, 600 };
	Paddle* lPaddle = new Paddle(20, 240, 200, ybounds, KEY_W, KEY_S);
	Paddle* rPaddle = new Paddle(760, 240, 200, ybounds, KEY_UP, KEY_DOWN);
	entityManager->AddEntity("left paddle", lPaddle);
	entityManager->AddEntity("right paddle", rPaddle);
}

void GameScene::Draw()
{
	entityManager->Draw();
}

SceneStatus GameScene::Update(float dt)
{
	auto audio = game->Audio();

	Scoreboard* scoreboard = (Scoreboard*)(entityManager->GetEntity("scoreboard"));
	Ball* ball = (Ball*)(entityManager->GetEntity("ball"));

	if (scoreboard->isReadying()) {
		scoreboard->Update(dt);
		return CONTINUE_UPDATES;
	}
	audio->AMUpdateMusicStream("game");

	entityManager->Update(dt);

	CheckPaddleCollisions(scoreboard, ball);
	CheckWallCollisions(ball);

	return CheckForWinner(scoreboard);
}

void GameScene::Reset()
{
	Scoreboard* scoreboard = (Scoreboard*)entityManager->GetEntity("scoreboard");
	Ball* ball = (Ball*)entityManager->GetEntity("ball");
	Paddle* lPaddle = (Paddle*)entityManager->GetEntity("left paddle");
	Paddle* rPaddle = (Paddle*)entityManager->GetEntity("right paddle");

	scoreboard->Reset();
	lPaddle->SetY(240);
	rPaddle->SetY(240);
	ball->Reset(Vector2{ 1, 1 });
	
	game->Audio()->AMPlaySound("ready");
	scoreboard->ReadyUp();
}

void GameScene::CheckPaddleCollisions(Scoreboard* scoreboard, Ball* ball)
{
	auto audio = game->Audio();
	// Ball collides with left paddle
	if (entityManager->CheckCollision("ball", "left paddle")) {
		audio->AMPlaySound("goal");
		audio->AMStopMusic("game");
		scoreboard->RightScored();
		ball->Reset(Vector2{ 1, 1 });
		audio->AMPlaySound("ready");
		scoreboard->ReadyUp();
		audio->AMPlayMusic("game");
	}

	// Ball collides with right paddle
	if (entityManager->CheckCollision("ball", "right paddle")) {
		audio->AMPlaySound("goal");
		audio->AMStopMusic("game");
		scoreboard->LeftScored();
		ball->Reset(Vector2{ -1, 1 });
		audio->AMPlaySound("ready");
		scoreboard->ReadyUp();
		audio->AMPlayMusic("game");
	}
}

void GameScene::CheckWallCollisions(Ball* ball)
{
	auto audio = game->Audio();
	// Ball collides with top or bottom wall
	if (ball->GetY() < wall.y || ball->GetY() > wall.height) {
		ball->Bounce(vertical);
		audio->AMPlaySound("bounce");
	}

	// Ball collides with left or right wall
	if (ball->GetX() < wall.x || ball->GetX() > wall.width) {
		ball->Bounce(horizontal);
		audio->AMPlaySound("bounce");
	}
}

SceneStatus GameScene::CheckForWinner(Scoreboard* scoreboard)
{
	auto scenes = game->Scenes();
	// Check scoreboard for a winner
	WinnerScene* winnerScene;
	switch (scoreboard->CheckWinner()) {
	case LEFT_WINS:
		Reset();

		winnerScene = new WinnerScene("Player 1", game);
		scenes->AddFrontScene(winnerScene);

		return STOP_UPDATES;
	case RIGHT_WINS:
		Reset();

		winnerScene = new WinnerScene("Player 2", game);
		scenes->AddFrontScene(winnerScene);

		return STOP_UPDATES;
	default:
		return CONTINUE_UPDATES;
	}
}
