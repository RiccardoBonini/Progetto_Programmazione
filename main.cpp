#include "SDL.h"
#include "Game.h"
#include <iostream>
#include "windows.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	int num;
	std::cout << "Inserire numero di nemici" << std::endl;
	std::cin >> num;
	game = new Game(num);
	game->init("Progetto", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 0, 0, false);
	
	while (game->gameIsRunning()){
		
		game->handleInput();
		game->update();
		game->render();
		//Sleep(30);
	}

	
	game->clean();
	std::cout << "Sei uscito" << std::endl;
	//system("pause");
	
	return 0;
}