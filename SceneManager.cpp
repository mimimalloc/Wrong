#include "SceneManager.h"

SceneManager::~SceneManager()
{
	ClearAllScenes();
}

void SceneManager::AddFrontScene(IScene* scene)
{
	scenes.push_front(scene);
	scene->Initialize();
}

void SceneManager::AddBackScene(IScene* scene)
{
	scenes.push_back(scene);
	scene->Initialize();
}

IScene* SceneManager::PopScene()
{
	IScene* scene = scenes.front();
	scenes.pop_front();
	return scene;
}

void SceneManager::EndScene()
{
	scenes.pop_front();
}

void SceneManager::ClearAllScenes()
{
	for (auto pointer : scenes) {
		delete pointer;
	}
	scenes.clear();
}

void SceneManager::ClearBackScenes()
{
	while (scenes.size() > 1) {
		delete scenes.back();
		scenes.pop_back();
	}
}

bool SceneManager::Update(float dt)
{
	for (IScene* scene : scenes) {
		// After updating, scenes return a status indicating what to
		// do next. By default, iteration continues until finished,
		// but if EXIT_SIGNAL or STOP_UPDATES are returned, updating
		// ends and a boolean representing whether to exit is in turn
		// returned to the Game
		switch (scene->Update(dt)) {
		case EXIT_SIGNAL:
			return true;
		case STOP_UPDATES:
			return false;
		case END_SCENE:
			if (scene == scenes.front()) {
				PopScene();
			}
			return false;
		default:
			break;
		}
	}
	return false;
}

void SceneManager::Draw()
{
	// Scenes are drawn from the bottom up - that means that scenes on the top are drawn on top
	if (!scenes.empty()) {
		for (int i = scenes.size() - 1; i >= 0; i--) {
			scenes.at(i)->Draw();
		}
	}
}
