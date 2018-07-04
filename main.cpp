#include "SDL.h"
#include "Game.h"
#include <iostream>
#include "windows.h"

Game *game = nullptr;

int main(int argc, char *argv[])
{
	int num1;
	int num2;
	int num3;
	std::cout << "Inserire numero di goblin" << std::endl;
	std::cin >> num1;
	std::cout << "Inserire numero di zombie" << std::endl;
	std::cin >> num2;
	std::cout << "Inserire numero di werewolf" << std::endl;
	std::cin >> num3;
	game = new Game(num1, num2, num3);
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