#pragma once
#include "Character.h"
#include "Projectile.h"
class Enemy:public Character
{
public:
	Enemy();
	~Enemy();
	void update();
	//void getHit(Projectile *p);
	void move();
};

