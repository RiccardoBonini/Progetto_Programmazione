#pragma once
#include "Enemy.h"
#include "Item.h"
#include "Bullet.h"
#include <vector>

class Enemy;

class Hero: public Character
{
public:
	Hero();
	Hero(int x, int y);
	~Hero();
	void move(bool dir, bool inc);
	void getItem(Item* item);
	void getHit(Enemy* enemy);
	void update();
	void draw() { std::cout << "O"; }
	void render();
	bool getUp() { return up; }
	bool getDown() { return down; }
	bool getLeft() { return left; }
	bool getRight() { return right; }
	void stopUp() { up = false; }
	void stopDown() { down = false; }
	void stopLeft() { left = false; }
	void stopRight() { right = false; }
	void free() { up = down = left = right = true; }
	void startUp() { up = true; }
	void startDown() { down = true; }
	void startLeft() { left = true; }
	void startRight() { right = true; }
	void color(int n1, int n2, int n3);
private:

	bool up, down, left, right;
	int spdw, spds, spdd, spda;
	int tmpspdw, tmpspds, tmpspdd, tmpspda;
	
};

