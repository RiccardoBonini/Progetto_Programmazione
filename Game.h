#pragma once
#include "SDL.h"
#undef main
#include <iostream>
#include "Hero.h"
#include "Character.h"
#include "Item.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Map.h"
#include "EnemyFactory.h"
#include"SDL_image.h"
#include<SDL_ttf.h>
#include<list>
#include "Text.h"

class Observer;

class Game
{
public:
	Game(int num);
	~Game();
	void init(const char* title, int x, int y, int width, int height, bool fullscreen);
	void handleExit();
	void handleInput();
	void update();
	void render();
	void clean();
	bool gameIsRunning() { return isRunning; }
	bool heroIsAlive() { return hero.isAlive(); }
	static bool CollisionC(Character a, Character* b);
	static bool CollisionB(Character*a, Bullet b);
	static bool CollisionHI(Character a, Item* b);
	static SDL_Renderer *renderer;
	static SDL_Texture* LoadTexture(const char* sprite);
	static void draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest);
	void notify();
	void attach(Observer * ob);
	int getDeadEnemies() { return deadEnemies; }
	int getBrokenThings() { return brokenThings; }
	void deadStrike();
	void massacre();
	void vandal();
	void adjustX(int speed);
	void adjustY(int speed);
	
private:
	bool isRunning;
	Item item;
	Hero hero;
	Map room;
	int enemiesNum;
	int deadEnemies;
	int brokenThings;
	std::vector<Observer*> observer;
	std::vector<Enemy*> enemies;
	std::vector<Bullet> bullets;
	std::vector<Item*> items;
	SDL_Window *window;
	Observer* sob;
	Observer* aob;
	int timer;
	bool strike;
	bool firstStrike;
	bool firstMassacre;
	bool firstVandal;
	int lastdir;
	std::vector<Text> text;
	std::vector<Text> score;
	Text punteggio;
	Text victory;
	Text lost;
	Text pressanykey;
	bool end;
	
};

