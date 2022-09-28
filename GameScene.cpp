#include "GameScene.h"
#include "Scoreboard.h"
#include "Ball.h"
#include "Paddle.h"
#include "WinnerScene.h"

GameScene::GameScene(EventQueue* eventQueue, SceneManager* sceneManager, AudioManager* audioManager):
	suppressUpdates(false), eventQueue(eventQueue), sceneManager(sceneManager), audioManager(audioManager),
	entityManager(new EntityManager())
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
	scoreboard->ReadyUp();

	Ball* ball = new Ball(BallBounds{ 0, 800, 0, 600 }, 150.0);
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

	// Ball collides with left paddle
	if (entityManager->CheckCollision("ball", "left paddle")) {
		audioManager->AMPlaySound("goal");
		scoreboard->RightScored();
		ball->Reset(Vector2{ 1, 1 });
		scoreboard->ReadyUp();
	}

	// Ball collides with right paddle
	if (entityManager->CheckCollision("ball", "right paddle")) {
		audioManager->AMPlaySound("goal");
		scoreboard->LeftScored();
		ball->Reset(Vector2{ -1, 1 });
		scoreboard->ReadyUp();
	}

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
	scoreboard->ReadyUp();
}
