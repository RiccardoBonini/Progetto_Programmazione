#pragma once
#include "Enemy.h"
#include "Item.h"
#include "Bullet.h"
#include <vector>

class Hero: public Character
{
public:
	Hero();
	Hero(float bound1, float bound2);
	~Hero();
	void move(bool dir, bool inc);
	void getItem(Item item);
	void getHit(Enemy enemy);
	void update();
	void render() { std::cout << "O"; }
private:
	float Xbound;
	float Ybound;
};

