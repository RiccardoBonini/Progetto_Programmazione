#pragma once
#include "Enemy.h"
#include "Item.h"
#include "Bullet.h"
#include <vector>
#include"SDL.h"
#include"SDL_image.h"
#include"TextureManager.h"


class Hero: public Character
{
public:
	Hero();
	Hero(float bound1, float bound2);
	~Hero();
	void move(bool dir, bool inc);
	void getItem(Item item);
	//void getHit(Enemy enemy);
	void update();
	void draw() { std::cout << "O"; }
	//SDL_Rect getRect() { return rect; }
	void render();
	int getRx() { return rect.x; }
	int getRy() { return rect.y; }
private:
	//SDL_Rect rect;
	SDL_Texture* heroTex;
	SDL_Rect rect;
	
};

