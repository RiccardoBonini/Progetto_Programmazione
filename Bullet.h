#pragma once
#include"SDL.h"
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
private:
	float coordX;
	float coordY;
	int damage;
	bool dir;
	bool inc;
	SDL_Rect rect;
	SDL_Texture* bulletTex;
};

