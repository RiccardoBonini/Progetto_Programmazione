#pragma once
#include "Enemy.h"
#include "Item.h"
class Map
{
public:
	Map();
	~Map();
	void dropItem();
	void spawnEnemy();
	float getWidth() { return width; }
	float getHeight() { return height; }
	void render() { std::cout << "#"; }
private:
	float height;
	float width;
	int RoomSeed;
};

