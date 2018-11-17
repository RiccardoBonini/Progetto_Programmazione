#pragma once
#include <iostream>
#include "Item.h"
#include"SDL.h"
#include"SDL_image.h"

class Character
{
public:
	Character();
	~Character();
	//virtual void update() = 0;
	int getX() { return coordX; }
	int getY() { return coordY; }
	int getHp() { return hp; }
	int getDmg() { return damage; }
	void incX(int i) { coordX += i; }
	void incY(int i) { coordY += i; }
	void decX(int i) { coordX -= i; }
	void setRx(int x) { rect.x = x; }
	void decY(int i) { coordY -= i; }
	void setRy(int y) { rect.y = y; }
	int getXbound() { return Xbound; }
	int getYbound() { return Ybound; }
	int getSpd() { return speed; }
	int getRx() { return rect.x; }
	int getRy() { return rect.y; }
	int getRh() { return rect.h; }
	int getRw() { return rect.w; }
	bool isAlive() { return alive; }
protected:
	int Xbound;
	int Ybound;
	int coordX;
	int coordY;
	float speed;
	int hp;
	int damage;
	bool alive;
	SDL_Texture* tex;
	SDL_Rect rect;
	bool damaged;
	int timer;
};

