#pragma once
#include "Character.h"
#include "Projectile.h"
class Enemy:public Character
{
public:
	Enemy();
	~Enemy();
	void update();
	void getShot(Projectile *p);
	void move();
};

