#include "GameScene.h"
#include "Scoreboard.h"

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
}

void GameScene::Draw()
{
	entityManager->Draw();
}

bool GameScene::Update(float dt)
{
	entityManager->Update(dt);

	return suppressUpdates;
}
