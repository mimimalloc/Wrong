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

void SceneManager::Update(float dt)
{
	for (IScene* scene : scenes) {
		// Updates end if a scene's update returns true - meaning the scene is "blocking"
		if (scene->Update(dt)) { 
			break; 
		}
	}
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
