#pragma once
#include "Enemy.h"
#include "Item.h"
class Room
{
public:
	Room();
	~Room();
	void dropItem();
	void spawnEnemy();
private:
	int height;
	int width;
	int RoomSeed;
};

