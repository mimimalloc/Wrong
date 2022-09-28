#include "GameScene.h"
#include "Paddle.h"
#include "WinnerScene.h"

GameScene::GameScene(EventQueue* eventQueue, SceneManager* sceneManager, AudioManager* audioManager):
	suppressUpdates(false), eventQueue(eventQueue), sceneManager(sceneManager), audioManager(audioManager),
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
	Scoreboard* scoreboard = new Scoreboard();
	entityManager->AddEntity("scoreboard", scoreboard);
	audioManager->AMPlaySound("ready");
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
	Scoreboard* scoreboard = (Scoreboard*)(entityManager->GetEntity("scoreboard"));
	Ball* ball = (Ball*)(entityManager->GetEntity("ball"));

	if (scoreboard->isReadying()) {
		scoreboard->Update(dt);
		return CONTINUE_UPDATES;
	}

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
	
	audioManager->AMPlaySound("ready");
	scoreboard->ReadyUp();
}

void GameScene::CheckPaddleCollisions(Scoreboard* scoreboard, Ball* ball)
{
	// Ball collides with left paddle
	if (entityManager->CheckCollision("ball", "left paddle")) {
		audioManager->AMPlaySound("goal");
		scoreboard->RightScored();
		ball->Reset(Vector2{ 1, 1 });
		audioManager->AMPlaySound("ready");
		scoreboard->ReadyUp();
	}

	// Ball collides with right paddle
	if (entityManager->CheckCollision("ball", "right paddle")) {
		audioManager->AMPlaySound("goal");
		scoreboard->LeftScored();
		ball->Reset(Vector2{ -1, 1 });
		audioManager->AMPlaySound("ready");
		scoreboard->ReadyUp();
	}
}

void GameScene::CheckWallCollisions(Ball* ball)
{
	// Ball collides with top or bottom wall
	if (ball->GetY() < wall.y || ball->GetY() > wall.height) {
		ball->Bounce(vertical);
		audioManager->AMPlaySound("bounce");
	}

	// Ball collides with left or right wall
	if (ball->GetX() < wall.x || ball->GetX() > wall.width) {
		ball->Bounce(horizontal);
		audioManager->AMPlaySound("bounce");
	}
}

SceneStatus GameScene::CheckForWinner(Scoreboard* scoreboard)
{
	// Check scoreboard for a winner
	WinnerScene* winnerScene;
	switch (scoreboard->CheckWinner()) {
	case LEFT_WINS:
		Reset();

		winnerScene = new WinnerScene("Player 1", eventQueue, sceneManager);
		sceneManager->AddFrontScene(winnerScene);

		return STOP_UPDATES;
	case RIGHT_WINS:
		Reset();

		winnerScene = new WinnerScene("Player 2", eventQueue, sceneManager);
		sceneManager->AddFrontScene(winnerScene);

		return STOP_UPDATES;
	default:
		return CONTINUE_UPDATES;
	}
}
