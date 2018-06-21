#pragma once
#include "SDL.h"
#include <iostream>
#include "Hero.h"
#include "Character.h"
#include "Item.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
class Game
{
public:
	Game(int num);
	~Game();
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleExit();
	void update();
	void render();
	void clean();
	bool gameIsRunning() { return isRunning; }
	bool heroIsAlive() { return hero.isAlive(); }
private:
	bool isRunning;
	Item item;
	Hero hero;
	Map room;
	//Enemy enemy;
	int enemynum;
	int roomWidth;
	int roomHeight;
	std::vector<Enemy> enemies;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

