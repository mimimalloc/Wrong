#include "raylib.h"
#include "Game.h"
#include "EventSystem.h"

int main() {
	Game* game = new Game();

	game->Initialize();
	game->Run();
	game->Exit();

	delete game;
}