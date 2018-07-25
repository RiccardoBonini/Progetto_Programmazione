#include "Game.h"


SDL_Renderer* Game::renderer = nullptr;

Game::Game(int num1, int num2, int num3)
{
	goblinNum = num1;
	zombieNum = num2;
	werewolfNum = num3;

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
	room =  Map() ;
	roomWidth = room.getWidth();
	roomHeight = room.getHeight();
	for (int i = 0; i < goblinNum; i++)
		enemies.push_back(EnemyFactory::makeEnemy('g',roomWidth, roomHeight));
	for (int i = 0; i < zombieNum; i++)
		enemies.push_back(EnemyFactory::makeEnemy('z', roomWidth, roomHeight));
	for (int i = 0; i < werewolfNum; i++)
		enemies.push_back(EnemyFactory::makeEnemy('w', roomWidth, roomHeight));
	hero= Hero(room.getWidth(), room.getHeight());
	
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

void Game::handleInput() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_w:
			hero.move(false, true);
			break;
		case SDLK_s:
			hero.move(false, false);
			break;
		case SDLK_d:
			hero.move(true, true);
			break;
		case SDLK_a:
			hero.move(true, false);
			break;
		case SDLK_i:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), false, true));
			break;
		case SDLK_k:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), false, false));
			break;
		case SDLK_l:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), true, true));
			break;
		case SDLK_j:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), true, false));
			break;

		}
	}
}

void Game::update() {
	
	hero.update();
	for (int j = 0; j < bullets.size(); j++) 
		bullets[j].update();/*
		for (int h = 0; h < enemies.size(); h++)
			if (bullets[j].getX() == enemies[h]->getX() && bullets[j].getY() == enemies[h]->getY())
				enemies.erase(enemies.begin() + h);
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->move();
		std::cout << "CordX di " << " " << i << ":" << " " << enemies[i]->getX();
		std::cout << " CordY di " << " " << i << ":" << " " << enemies[i]->getY();
		
	}
	std::cout << room.getHeight();
	std::cout << room.getWidth();*/
	
}

void Game::render() {
	SDL_RenderClear(renderer);
	room.drawMap();
	hero.render();
	for (int j = 0; j < bullets.size(); j++)
		bullets[j].render();
	SDL_RenderPresent(renderer);
	/*system("cls");
	for (int i = 0; i < roomWidth; i++) {
		room.render();
	}
	std::cout << " enemies count: "<< enemies.size()<<std::endl;
	for (int i = 0; i < roomHeight - 1; i++) {
		room.render();
		for (int j = 0; j < roomWidth - 2; j++) {
			for (int k = 0; k < bullets.size(); k++) {
				if (j == bullets[k].getX() && i == bullets[k].getY())
					std::cout << "*";
			}
			for (int e = 0; e < enemies.size(); e++) {
				if (i == enemies[e]->getY() && j == enemies[e]->getX())
					enemies[e]->draw();
			}
			if (j == hero.getX() && i == hero.getY())
				hero.draw();
			else	
				std::cout << " ";

		}
		std::cout << "#" << std::endl;
	}
	for (int i = 0; i <roomWidth; i++) {
		std::cout << "#";
	}
	std::cout << std::endl;
	std::cout << hero.getX() << " " << hero.getY();*/
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}
