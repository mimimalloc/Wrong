#pragma once
#include "Entity.h"
#include "raylib.h"
#include <string>
class Scoreboard : public Entity
{
public:
	Scoreboard();
	~Scoreboard();

	void ReadyUp();

	void Update(float dt);
	void Draw();
private:
	Font font;
	int leftScore;
	int rightScore;
	bool getReady;
	float readyTimer;
	bool flashVisible;
	float flashTimer;	
};

