#pragma once
#include "IScene.h"
#include "SceneManager.h"
#include "EventSystem.h"

class NewSceneEvent : public Event
{
public:
	NewSceneEvent(SceneManager* sm, IScene* scene, bool clearFirst = true, bool atFront = true);

	void Start();
	void Run(float dt) {}
	void End() {}
private:
	SceneManager* sceneManager;
	IScene* newScene;
	bool clearFirst;
	bool atFront;
};

