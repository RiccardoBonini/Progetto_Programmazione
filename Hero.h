#pragma once
#include "Character.h"
#include "Item.h"
#include "Projectile.h"

class Hero: public Character
{
public:
	Hero();
	~Hero();
	void handleInput();
	void getItem(Item *item);
	void getHit(Character *enemy);
	void update();

	
};

