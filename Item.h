#pragma once
#include"SDL.h"
#undef main
#include"SDL_image.h"
class Item
{
public:
	Item();
	~Item();
	int getRx() { return rect.x; }
	int getRy() { return rect.y; }
	int getRh() { return rect.h; }
	int getRw() { return rect.w; }
	int getHp() { return hpValue; }
	int getDmg() { return damageValue; }
	float getSpd() { return speedValue; }
	void render();
	void erase() { erasable = true; }
	bool isErasable() { return erasable; }
	void setRx(int x) { rect.x = x; }
	void setRy(int y) { rect.y = y; }
protected:
	float coordX;
	float coordY;
	int dropRate;
	int hpValue;
	int damageValue;
	float speedValue;
	bool erasable;
	SDL_Texture* tex;
	SDL_Rect rect;	
};

class Potion :public Item {
public:
	Potion(int x, int y);
};

class Bazooka :public Item {
public:
	Bazooka(int x, int y);
};

class MightyFork : public Item {
public:
	MightyFork(int x, int y);
};

