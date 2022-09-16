/**
	Wrong!

	It's like Pong, but Wrong!
	Avoid touching the ball with your paddle.

	Whoever reaches 10 points first wins!

	This is a learning project. Many aspects of this program
	are overcomplicated for the sake of trying something that
	might be more extensible than hard-coding everything.

	This game by Noemi Banks (mimimalloc)
*/

#include "raylib.h"
#include "Game.h"
#include "OverlayEntity.h"

// The global overlay can be accessed anywhere in order
// to i.e. fade the screen
OverlayEntity* g_overlay = new OverlayEntity();



int main() {
	Game* game = new Game();
	
	// Initialize and run the game. Run manages the two game loops,
	// so when it ends it's time to prepare to exit.
	game->Initialize();
	game->Run();
	game->Exit();

	delete game;
}