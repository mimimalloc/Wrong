#include "raylib.h"
#include "Game.h"

int main() {
	Game game;
	game.Initialize();
	game.Run();
	game.Exit();
}