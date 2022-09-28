#pragma once
#include "IScene.h"
#include "EventSystem.h"
#include "SceneManager.h"
#include "EntityManager.h"
#include "raylib.h"
#include "AudioManager.h"

/**
	[ GameScene ]
	Scene that runs the game itself.
	Manages the two paddles, the ball,
	and collisions between these and the walls
*/
class GameScene : public IScene
{
public:
	GameScene(EventQueue* eventQueue, SceneManager* sceneManager, AudioManager* audioManager);
	~GameScene();

	void Initialize();
	void Draw();
	SceneStatus Update(float dt);
private:
	// Resets the ball and scoreboard
	void Reset();
	// Checks and handles the ball colliding with the paddles
	void CheckPaddleCollisions();

	// Whether the scene suppresses later scene's update calls
	bool suppressUpdates;
	// The wall that the ball bounces against
	Rectangle wall;
	// The main EventQueue
	EventQueue* eventQueue;
	// The main SceneManager
	SceneManager* sceneManager;
	// The main AudioManager
	AudioManager* audioManager;
	// This scene's EntityManager
	EntityManager* entityManager;
};

