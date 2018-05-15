#pragma once
#include "Hero.h"
class Projectile
{
public:
//	Projectile(Hero* hero, bool Dir, bool Inc);
	~Projectile();
	void update();
	float getX() { return coordX; };
	float gety() { return coordY; };
	int getDmg() { return damage; };
private:
	float coordX;
	float coordY;
	int damage;
	bool dir;
	bool inc;
	
};

