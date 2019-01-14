#pragma once
#include"Tile.h"
#include<vector>
#include "SDL.h"
#undef main
#include "SDL_image.h"
#include"EnemyFactory.h"

class Map
{
public:
	Map();
	~Map();
	void dropItem();
	int getWidth() { return width; }
	int getHeight() { return height; }
	void drawMap();
	void loadMap();
	void update();
	Tile* getTile(int i) { return tiles[i]; }
	int mapSize() { return tiles.size(); }
	bool solidTile(int i) { return tiles[i]->solid(); }
	int getTileX(int i) { return tiles[i]->getRx(); }
	int getTileY(int i) { return tiles[i]->getRy(); }
	int getTileH(int i) { return tiles[i]->getRh(); }
	int getTileW(int i) { return tiles[i]->getRw(); }
	void CollisionBW(std::vector<Bullet> &bullets, int &brokenThings);
	static bool CollisionCW(int x, int y, int w, int h, Tile *t);
	bool CollisionCWup(int x, int y, int w, int h, int speed);
	bool CollisionCWdown(int x, int y, int w, int h, int speed);
	bool CollisionCWleft(int x, int y, int w, int h, int speed);
	bool CollisionCWright(int x, int y, int w, int h, int speed);
	void setUp(Character &hero);
	void setDown(Character &hero);
	void setLeft(Character &hero);
	void setRight(Character &hero);
	void spawnEnemies(std::vector<Enemy*> &enemies,int enemiesNum);
	bool CollisionEnemy(int x, int y, int w, int h);
	void erase();
	void adjustX(int speed);
	void adjustY(int speed);
private:
	int height;
	int width;
	std::vector<Tile*> tiles;
	int ntile;
	Tile* target;
};

