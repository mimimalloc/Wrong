#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "SceneManager.h"
#include <string>
#include "EntityManager.h"
class WinnerScene : public IScene
{
public:
	WinnerScene(std::string winner, EventQueue* eq, SceneManager* sm);
	~WinnerScene();

	void Initialize();
	SceneStatus Update(float dt);
	void Draw();

private:
	Font font;
	std::string winner;
	EventQueue* eventQueue;
	SceneManager* sceneManager;
	EntityManager* entityManager;
};

