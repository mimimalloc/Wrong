#pragma once
#include "Entity.h"
#include "raylib.h"
#include <string>

/**
	[ GameWinner ]
	Enum for the current winner of the game
*/
enum GameWinner {
	NO_WINNER, LEFT_WINS, RIGHT_WINS
};

/**
	[ Scoreboard ]
	An entity that is responsible for drawing the players' scores
	to the screen, and the "GET READY!" text when a round 
	is about to begin
*/
class Scoreboard : public Entity
{
public:
	Scoreboard(Vector2 leftPos, Vector2 rightPos);
	~Scoreboard();

	// Set the scoreboard to ready state to display the ready text
	void ReadyUp();
	// Returns true if the ready state is active
	bool isReadying();

	// Increases the left player's score by 1
	void LeftScored();
	// Increases the right player's score by 1
	void RightScored();

	// Returns the left player's current score
	int GetLeftScore();
	// Returns the right player's current score
	int GetRightScore();

	// Resets the values of the scoreboard and activates ready state
	void Reset();

	// Checks whether a player has won
	GameWinner CheckWinner();

	void Update(float dt);
	void Draw();
private:
	// The font the entity uses to draw text
	Font font;
	// The score of the left player
	int leftScore;
	// The score of the right player
	int rightScore;
	// The position where the left players' score is drawn
	Vector2 leftPos;
	// The position where the right players' score is drawn
	Vector2 rightPos;
	// True if the ready state is active
	bool getReady;
	// When this timer reaches a specified limit,
	// ready state is deactivated
	float readyTimer;
	// When true, the ready text is displayed (not flashing invisible)
	bool flashVisible;
	// When this timer reaches a specified limit,
	// the ready text flashes visible/invisible
	float flashTimer;
};

