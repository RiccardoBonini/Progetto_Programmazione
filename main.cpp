#include "SDL.h"
#include "Game.h"
#include <iostream>


Game *game = nullptr;

int main(int argc, char *argv[])
{
	game = new Game();
	game->init("Progetto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 700, 700, false);
	while (game->gameIsRunning()){
		
		
		game->update();
		game->render();
		
	}

	
	game->clean();
	std::cout << "Sei uscito" << std::endl;
	system("pause");
	
	return 0;
}