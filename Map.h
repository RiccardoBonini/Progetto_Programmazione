#pragma once
//#include "Enemy.h"
//#include "Item.h"
#include"Tile.h"
#include<vector>
#include "SDL.h"
#include "SDL_image.h"
#include"EnemyFactory.h"

class Map
{
public:
	Map();
	~Map();
	void dropItem();
	void spawnEnemy();
	int getWidth() { return width; }
	int getHeight() { return height; }
	//void render() { std::cout << "#"; }
	void drawMap();
	void loadMap();
	void update();
private:
	int height;
	int width;
	std::vector<Tile*> tiles;
	int ntile;
};

