#pragma once

#include <queue>
#include "IScene.h"
#include "Game.h"

/**
	[ SceneManager ]
	A SceneManager is responsible for holding, updating, and drawing 
	its scenes. Scenes are updated from front to back, but they are
	drawn from back to front, so that scenes on top of the deque
	are drawn on top of other scenes.
*/
class SceneManager
{
public:
	SceneManager() {};
	~SceneManager();

	// Adds a scene to the front of the deque
	void AddFrontScene(IScene* scene);

	// Adds a scene to the back of the deque
	void AddBackScene(IScene* scene);

	// Removes and returns a pointer to a scene from the front of the deque.
	IScene* PopScene();

	// Removes the front scene from the deque without returning its pointer
	void EndScene();

	// Removes all scenes from the deque and frees their memory
	void ClearAllScenes();

	// Removes all scenes from the deque and frees their memory,
	// except for the scene in front
	void ClearBackScenes();

	// Returns true if the deque is empty
	inline bool IsEmpty() { return scenes.empty(); }

	// If Update returns true, it communicates to the game that a scene
	// returned the exit signal
	bool Update(float dt);
	void Draw();
private:
	// The deque that contains pointers to all the scenes
	// the instance manages
	std::deque<IScene*> scenes;
};

