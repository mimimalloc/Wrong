#include "GameScene.h"
#include "Scoreboard.h"
#include "Ball.h"
#include "Paddle.h"

GameScene::GameScene(EventQueue* eventQueue, SceneManager* sceneManager):
	suppressUpdates(false), eventQueue(eventQueue), sceneManager(sceneManager),
	entityManager(new EntityManager())
{
}

GameScene::~GameScene()
{
}

void GameScene::Initialize()
{
	Scoreboard* scoreboard = new Scoreboard();
	entityManager->AddEntity("scoreboard", scoreboard);
	scoreboard->ReadyUp();

	Ball* ball = new Ball(BallBounds{ 0, 800, 0, 600 }, 1000.0);
	entityManager->AddEntity("ball", ball);

	Vector2 ybounds{ 0, 600 };
	Paddle* lPaddle = new Paddle(20, 300, 200, ybounds, KEY_W, KEY_S);
	Paddle* rPaddle = new Paddle(760, 300, 200, ybounds, KEY_UP, KEY_DOWN);
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

	if (scoreboard->isReadying()) {
		scoreboard->Update(dt);
		return CONTINUE_UPDATES;
	}

	entityManager->Update(dt);

	// Ball collides with left paddle
	if (entityManager->CheckCollision("ball", "left paddle")) {
		Ball* ball = (Ball*)(entityManager->GetEntity("ball"));

		scoreboard->RightScored();
		ball->Reset(Vector2{ 1, 1 });
		scoreboard->ReadyUp();
	}

	// Ball collides with right paddle
	if (entityManager->CheckCollision("ball", "right paddle")) {
		Ball* ball = (Ball*)(entityManager->GetEntity("ball"));

		scoreboard->LeftScored();
		ball->Reset(Vector2{ -1, 1 });
		scoreboard->ReadyUp();
	}

	// Check scoreboard for a winner
	switch (scoreboard->CheckWinner()) {
	case LEFT_WINS:
		return EXIT_SIGNAL;
	case RIGHT_WINS:
		return EXIT_SIGNAL;
	default:
		return CONTINUE_UPDATES;
	}
}
