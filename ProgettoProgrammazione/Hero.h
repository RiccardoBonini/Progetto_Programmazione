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
	void handleInput();
	void shoot( bool Dir, bool Inc);
	void getItem(Item item);
	void getHit(Enemy enemy);
	void update();
	void render() { std::cout << "O"; }
	std::vector<Bullet> getBullets() { return this->bullets; }
private:
	float Xbound;
	float Ybound;
	std::vector<Bullet> bullets;
};

