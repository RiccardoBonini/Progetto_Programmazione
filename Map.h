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
	int getWidth() { return width; }
	int getHeight() { return height; }
	void render() { std::cout << "#"; }
	void drawMap();
private:
	int height;
	int width;
	int RoomSeed;
	SDL_Rect src, dest;
	SDL_Texture* wall;
	SDL_Texture* terrain;
	int map[20][20];
};

