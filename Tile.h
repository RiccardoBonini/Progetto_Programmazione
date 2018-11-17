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
	int getRx() { return rect.x; }
	int getRy() { return rect.y; }
	int getRh() { return rect.h; }
	int getRw() { return rect.w; }
	bool solid() { return collision; }
protected:
	SDL_Texture * tileTex;
	SDL_Rect rect;
	bool collision;
};

class Wall :public Tile {
public:
	Wall(int x, int y);
	//bool solid() { return collision; }
	//void render();
};

class Ground : public Tile {
public:
	Ground(int x, int y);
	//bool solid() { return collision; }
	//void render();
};

