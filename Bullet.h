#pragma once
#include"SDL.h"
#undef main
#include"SDL_image.h"


class Bullet
{
public:
	Bullet(float X, float Y, bool Dir, bool Inc);
	~Bullet();
	void update();
	float getX() { return coordX; };
	float getY() { return coordY; };
	int getDmg() { return damage; };
	void render();
	int getRx() { return rect.x; }
	int getRy() { return rect.y; }
	int getRh() { return rect.h; }
	int getRw() { return rect.w; }
	void erase();
	void eraseBullet() { erasable = true; }
	bool isErasable() { return erasable; }
private:
	float coordX;
	float coordY;
	int damage;
	bool dir;
	bool inc;
	bool erasable;
	int speed;
	SDL_Rect rect;
	SDL_Texture* bulletTex;
};

