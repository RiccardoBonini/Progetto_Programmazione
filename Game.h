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
	Game(int num1, int num2, int num3);
	~Game();
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleExit();
	void handleInput();
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
	int goblinNum;
	int zombieNum;
	int werewolfNum;
	int roomWidth;
	int roomHeight;
	std::vector<Enemy*> enemies;
	std::vector<Bullet> bullets;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

