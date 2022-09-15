#pragma once

#include <queue>
#include "IScene.h"

class SceneManager
{
public:
	SceneManager() {};
	~SceneManager();

	void AddFrontScene(IScene* scene);
	void AddBackScene(IScene* scene);
	IScene* PopScene();
	void ClearAllScenes();
	void ClearBackScenes();
	inline bool IsEmpty() { return scenes.empty(); }

	void Update(float dt);
	void Draw();
private:
	std::deque<IScene*> scenes;
};

