#include "GameScene.h"
#include "Scoreboard.h"
#include "Ball.h"

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

	Ball* ball = new Ball(BallBounds{ 0, 800, 0, 600 }, 100.0);
	entityManager->AddEntity("ball", ball);
}

void GameScene::Draw()
{
	entityManager->Draw();
}

bool GameScene::Update(float dt)
{
	Scoreboard* scoreboard = (Scoreboard*)(entityManager->GetEntity("scoreboard"));

	if (!scoreboard->isReadying()) {
		entityManager->Update(dt);
	}
	else {
		scoreboard->Update(dt);
	}

	return suppressUpdates;
}
