#pragma once
#include "SDL.h"
#include "SDL_image.h"

class Tile
{
public:
	//Tile();
	~Tile();
	void render();
	void update();

protected:
	SDL_Texture * tileTex;
	SDL_Rect rect;
	//bool collision;
};

class Wall :public Tile {
public:
	Wall(int x, int y);
	//void render();
};

class Ground : public Tile {
public:
	Ground(int x, int y);
	//void render();
};

