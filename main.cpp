#include "SDL.h"
#undef main
#include "Game.h"
#include <iostream>


Game *game = nullptr;

int main(int argc, char *argv[])
{
	

	game = new Game(10);
	game->init("Progetto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1200, 800, true);
	
	while (game->gameIsRunning()){
		
		game->handleInput();
		game->update();
		game->render();
		
	}

	
	game->clean();
	std::cout << "Sei uscito" << std::endl;
	
	
	return 0;
}