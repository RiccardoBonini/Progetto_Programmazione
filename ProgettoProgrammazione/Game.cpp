#include "Game.h"
#include "Hero.h"


Game::Game(int num)
{
	enemynum = num;
}


Game::~Game()
{
}

void Game::init(const char *title, int x, int y, int width, int height, bool fullscreen) {
	
	int screen = 0;
	if (fullscreen == true)
		screen = SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){
	window = SDL_CreateWindow(title, x, y, width, height, screen);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);}
	isRunning = true;
	item ;
	room ;
	for (int i = 0; i < enemynum; i++)
		enemies.push_back(Enemy(room.getWidth(), room.getHeight()));
	hero= Hero(room.getWidth(), room.getHeight());
	roomWidth = room.getWidth();
	roomHeight = room.getHeight();
}

void Game::handleExit(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	}
	
}

void Game::update() {
	
	hero.update();
	//for (int i = 0; i< enemies.size(); i++)
		//enemies[i].roam();
	
}

void Game::render() {
	//SDL_RenderClear(renderer);
	//SDL_RenderPresent(renderer);
	system("cls");
	std::vector<Bullet> tmp = hero.getBullets();
	for (int i = 0; i < roomWidth; i++) {
		room.render();
	}
	std::cout << " enemies count: "<< enemies.size()<<std::endl;
	for (int i = 0; i < roomHeight - 1; i++) {
		room.render();
		for (int j = 0; j < roomWidth - 2; j++) {
			for (int k = 0; k < tmp.size(); k++) {
				if (j == tmp[k].getX() && i == tmp[k].getY())
					std::cout << "*";
				for (int h = 0; h < enemies.size(); h++)
					if (tmp[k].getX() == enemies[h].getX() && tmp[k].getY() == enemies[h].getY())
						enemies.erase(enemies.begin() +h);
			}
			for (int e = 0; e < enemies.size(); e++) {
				if (i == enemies[e].getY() && j == enemies[e].getX())
					std::cout << "M";
			}
			if (j == hero.getX() && i == hero.getY())
				std::cout << "O"/*hero->draw()*/;
			else	
				std::cout << " ";

		}
		std::cout << "#" << std::endl;
	}
	for (int i = 0; i <roomWidth; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << hero.getX() << " " << hero.getY();
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
