#pragma once
#include "Character.h"
#include "Item.h"
#include "Projectile.h"
#include "Enemy.h"
class Hero: public Character
{
public:
	Hero();
	~Hero();
	void handleInput();
	void getItem(Item *item);
	//void getHit(Enemy *enemy);
	void update();
	
};

