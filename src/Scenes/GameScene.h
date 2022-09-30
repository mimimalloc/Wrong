#pragma once
#include "raylib.h"
#include "IScene.h"
#include "SceneManager.h"
#include "../Entities/EntityManager.h"
#include "../Events/EventSystem.h"
#include "../AudioManager.h"
#include "../Entities/Scoreboard.h"
#include "../Entities/Ball.h"
#include "../Game.h"
#include "../Entities/Paddle.h"

/**
	[ GameScene ]
	Scene that runs the game itself.
	Manages the two paddles, the ball,
	and collisions between these and the walls
*/
class GameScene : public IScene
{
public:
	GameScene(Game* game);
	~GameScene();

	void Initialize();
	void Draw();
	SceneStatus Update(float dt);
private:
	// Resets the ball and scoreboard
	void Reset();
	// Checks and handles the ball colliding with the paddles
	void CheckPaddleCollisions(Scoreboard* scoreboard, Ball* ball, Paddle* lPaddle, Paddle* rPaddle);
	// Checks and handles the ball colliding with the walls
	void CheckWallCollisions(Ball* ball);
	// Checks and handles what occurs when a player reaches 10
	// points and wins. Returns the SceneStatus the GameScene
	// should return from Update
	SceneStatus CheckForWinner(Scoreboard* scoreboard);

	// Whether the scene suppresses later scene's update calls
	bool suppressUpdates;
	// The wall that the ball bounces against
	Rectangle wall;
	// Pointer to the game object
	Game* game;
	// This scene's EntityManager
	EntityManager* entityManager;
};

