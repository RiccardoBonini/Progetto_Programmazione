#pragma once
#include "SDL.h"
#undef main
#include "SDL_image.h"


class Tile
{
public:
	~Tile();
	void render();
	void update();
	int getRx() { return rect.x; }
	int getRy() { return rect.y; }
	int getRh() { return rect.h; }
	int getRw() { return rect.w; }
	void setRx(int x) { rect.x = x; }
	void setRy(int y) { rect.y = y; }
	bool solid() { return collision; }
	bool spawnPoint() { return spawn; }
	bool isBreakable() { return breakable; }
	bool isErasable() { return erasable; }
	void erase() { erasable = true; }
protected:
	SDL_Texture * tileTex;
	SDL_Rect rect;
	SDL_Rect srect;
	bool collision;
	bool breakable;
	bool spawn;
	bool erasable;
	int posx;
	int posy;
};

class Wall :public Tile {
public:
	Wall(int x, int y);
	
};

class Ground : public Tile {
public:
	Ground(int x, int y, bool spn);
	

};

class Pillar : public Tile {
public:
	Pillar(int x, int y);
	
};

class Barrel : public Tile {
public:
	Barrel(int x, int y);

};

