#pragma once
#include "IScene.h"
#include "SceneManager.h"
#include "EventSystem.h"

/**
	[ NewSceneEvent ]
	This event uses a pointer to a SceneManager to add
	a scene. By default, it clears all other scenes to
	do so and places the new scene at the front of
	the deque, but you can change this behavior with
	optional booleans.
*/
class NewSceneEvent : public Event
{
public:
	// Takes a scene manager pointer, a scene pointer, and optionally two booleans that
	// determine how the scene manager functions.
	NewSceneEvent(SceneManager* sm, IScene* scene, bool clearFirst = true, bool atFront = true);

	void Start();
	void Run(float dt) {}
	void End() {}
private:
	// Pointer to the scene manager
	SceneManager* sceneManager;
	// The scene that will be added to the scene manager
	IScene* newScene;
	// If true, the SceneManager clears its scenes before adding the scene
	bool clearFirst;
	// If true, the newScene will be added to the front of the SceneManager
	// If false, it will be added to the back instead
	bool atFront;
};

