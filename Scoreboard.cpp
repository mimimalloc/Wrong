#include "Scoreboard.h"

float FLASH_RATE = 0.4f;
float READY_TIME = 3.0f;

Scoreboard::Scoreboard():
	Entity(0, 0, 0, 0, 1.0f),
	leftScore(0), rightScore(0), getReady(false), flashVisible(true), flashTimer(0), readyTimer(0)
{
	font = LoadFont("resources/RaccoonSerif-Bold.ttf");
}

Scoreboard::~Scoreboard()
{
	UnloadFont(font);
}

void Scoreboard::ReadyUp()
{
	getReady = true;
}

bool Scoreboard::isReadying()
{
	return getReady;
}

void Scoreboard::LeftScored()
{
	leftScore += 1;
}

void Scoreboard::RightScored()
{
	rightScore += 1;
}

int Scoreboard::GetLeftScore()
{
	return leftScore;
}

int Scoreboard::GetRightScore()
{
	return rightScore;
}

void Scoreboard::Reset()
{
	leftScore = 0;
	rightScore = 0;
	flashVisible = true;
	readyTimer = 0;
	flashTimer = 0;
	getReady = true;
}

GameWinner Scoreboard::CheckWinner()
{
	if (leftScore >= 10) {
		return LEFT_WINS;
	}
	else if (rightScore >= 10) {
		return RIGHT_WINS;
	}
	else {
		return NO_WINNER;
	}
}

void Scoreboard::Update(float dt)
{
	// If the scoreboard is in ready state, increment the timers
	if (getReady) {
		readyTimer += dt;
		flashTimer += dt;
		// Flash the GET READY! text by toggling the boolean
		if (flashTimer >= FLASH_RATE) {
			flashVisible = !flashVisible;
			flashTimer = 0;
		}
		// Leave ready state when the timer reaches the set value
		if (readyTimer >= READY_TIME) {
			getReady = false;
			readyTimer = 0;
		}
	}
}

void Scoreboard::Draw()
{
	// Draw left and right score values
	DrawText(std::to_string(leftScore).c_str(), 40, 20, 64, WHITE);
	DrawText(std::to_string(rightScore).c_str(), 700, 20, 64, WHITE);

	// Draw "GET READY!" when in ready state and flashVisible is true
	if (getReady && flashVisible) {
		DrawText("GET READY!", 240, 200, 48, WHITE);
	}
}
