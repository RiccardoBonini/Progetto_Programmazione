#pragma once
#include "SDL.h"
#include <iostream>
#include "Hero.h"
#include "Character.h"
#include "Item.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
#include "EnemyFactory.h"
/*#include "Tile.h"
#include"TileFactory.h"*/
#include"SDL_image.h"
#include<SDL_ttf.h>
//#include "Observer.h"
#include<list>

class Observer;

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
	bool CollisionC(Character a, Character* b);
	bool CollisionB(Character*a, Bullet b);
	/*bool CollisionWup(Character a, Tile* t);
	bool CollisionWdown(Character a, Tile* t);
	bool CollisionWleft(Character a, Tile* t);
	bool CollisionWright(Character a, Tile* t);*/
	/*bool CollisionW(Character a, Tile* t);
	bool under(Character a, Tile* t);
	bool over(Character a, Tile* t);
	bool left(Character a, Tile* t);
	bool right(Character a, Tile* t);
	//bool CollisionBW(Bullet a, Tile*t);*/
	bool CollisionHI(Character a, Item* b);
	static SDL_Renderer *renderer;
	static SDL_Texture* LoadTexture(const char* sprite);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	void drawScore(SDL_Renderer * rend);
	void notify();
	void attach(Observer * ob);
	int getDeadEnemies() { return deadEnemies; }
	void deadStrike();
private:
	bool isRunning;
	Item item;
	Hero hero;
	Map room;
	int goblinNum;
	int zombieNum;
	int werewolfNum;
	int roomWidth;
	int roomHeight;
	int solidSize;
	int deadEnemies;
	std::vector<Observer*> observer;
	std::vector<Enemy*> enemies;
	std::vector<Bullet> bullets;
	std::vector<Item*> items;
	/*std::list<Item*> items;
	std::list<Item*>::iterator itItems;*/
	SDL_Window *window;
	Observer* sob;
	int timer;
	bool strike;
	bool firstStrike;
	int lastdir;
	
};

