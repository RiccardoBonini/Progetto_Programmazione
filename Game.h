#pragma once
#include "SDL.h"
#include <iostream>
#include "Hero.h"
#include "Character.h"
#include "Item.h"
#include "Enemy.h"
#include "Projectile.h"
class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleExit();
	void update();
	void render();
	void clean();
	bool gameIsRunning() { return isRunning; }
	bool heroIsAlive() { return hero->isAlive(); }
private:
	bool isRunning;
	Item *item;
	Hero *hero;
	SDL_Window *window;
	SDL_Renderer *renderer;
};

