#include "GameScene.h"
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

	Scoreboard* scoreboard = new Scoreboard(
		{ game->Screen()->topLeft.x + 80 , game->Screen()->topLeft.y + 32 },
		{ game->Screen()->topRight.x - 112, game->Screen()->topRight.y + 32 }
	);
	entityManager->AddEntity("scoreboard", scoreboard);
	audio->AMPlaySound("ready");
	scoreboard->ReadyUp();

	Ball* ball = new Ball(150.0);
	ball->SetPosCentered(game->Screen()->midCenter);
	entityManager->AddEntity("ball", ball);

	Vector2 ybounds{ 0, 600 };
	float paddleY = game->Screen()->midCenter.y - 60;
	float lPaddleX = game->Screen()->midLeft.x + 30;
	float rPaddleX = game->Screen()->midRight.x - 50;
	Paddle* lPaddle = new Paddle(lPaddleX, paddleY, 300, ybounds, KEY_W, KEY_S);
	Paddle* rPaddle = new Paddle(rPaddleX, paddleY, 300, ybounds, KEY_UP, KEY_DOWN);

	entityManager->AddEntity("left paddle", lPaddle);
	entityManager->AddEntity("right paddle", rPaddle);
}

void GameScene::Draw()
{
	entityManager->Draw();
}

SceneStatus GameScene::Update(float dt)
{
	Scoreboard* scoreboard = (Scoreboard*)entityManager->GetEntity("scoreboard");
	Ball* ball = (Ball*)entityManager->GetEntity("ball");
	Paddle* lPaddle = (Paddle*)entityManager->GetEntity("left paddle");
	Paddle* rPaddle = (Paddle*)entityManager->GetEntity("right paddle");

	if (scoreboard->isReadying()) {
		scoreboard->Update(dt);
		return CONTINUE_UPDATES;
	}
	game->Audio()->AMUpdateMusicStream("game");

	entityManager->Update(dt);

	CheckPaddleCollisions(scoreboard, ball, lPaddle, rPaddle);
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
	lPaddle->ResetPos();
	lPaddle->ResetSpeed();
	rPaddle->ResetPos();
	rPaddle->ResetSpeed();
	ball->Reset(Vector2{ 1, 1 });
	
	game->Audio()->AMPlaySound("ready");
	scoreboard->ReadyUp();
}

void GameScene::CheckPaddleCollisions(Scoreboard* scoreboard, Ball* ball, Paddle* lPaddle, Paddle* rPaddle)
{
	auto audio = game->Audio();
	// Ball collides with left paddle
	if (entityManager->CheckCollision("ball", "left paddle")) {
		audio->AMPlaySound("goal");
		audio->AMStopMusic("game");

		scoreboard->RightScored();
		ball->Reset(Vector2{ 1, 1 });
		lPaddle->ResetPos();
		rPaddle->ResetPos();

		lPaddle->SpeedUp(1 + (scoreboard->GetRightScore() * 0.04));

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
		lPaddle->ResetPos();
		rPaddle->ResetPos();

		rPaddle->SpeedUp(1 + (scoreboard->GetLeftScore() * 0.04));

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
	// Check scoreboard for a winner
	WinnerScene* winnerScene;
	switch (scoreboard->CheckWinner()) {
	case LEFT_WINS:
		Reset();

		winnerScene = new WinnerScene("Player 1", game);
		game->Scenes()->AddFrontScene(winnerScene);

		return STOP_UPDATES;
	case RIGHT_WINS:
		Reset();

		winnerScene = new WinnerScene("Player 2", game);
		game->Scenes()->AddFrontScene(winnerScene);

		return STOP_UPDATES;
	default:
		return CONTINUE_UPDATES;
	}
}
