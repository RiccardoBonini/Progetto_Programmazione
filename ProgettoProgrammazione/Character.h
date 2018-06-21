#pragma once
#include <iostream>
#include "Item.h"

class Character
{
public:
	Character();
	~Character();
	void draw();
	virtual void update() = 0;
	float getX() { return coordX; }
	float getY() { return coordY; }
	int getDmg() { return damage; }
	bool isAlive() { return alive; }
protected:
	float Xbound;
	float Ybound;
	float coordX;
	float coordY;
	float speed;
	int hp;
	int damage;
	bool alive;
};

