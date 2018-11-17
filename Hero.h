#pragma once
#include "Enemy.h"
#include "Item.h"
#include "Bullet.h"
#include <vector>
/*#include"SDL.h"
#include"SDL_image.h"*/
//#include"TextureManager.h"


class Hero: public Character
{
public:
	Hero();
	Hero(float bound1, float bound2);
	~Hero();
	void move(bool dir, bool inc);
	void getItem(Item* item);
	void getHit(Enemy* enemy);
	void update();
	void draw() { std::cout << "O"; }
	void render();
	bool getUp() { return up; }
	bool getDown() { return down; }
	bool getLeft() { return left; }
	bool getRight() { return right; }
	void stopUp() { up = false; }
	void stopDown() { down = false; }
	void stopLeft() { left = false; }
	void stopRight() { right = false; }
	void free() { up = down = left = right = true; }
	/*void stopW() { tmpspdw = spdw; spdw = 0; }
	void stopS() { tmpspds = spds; spds = 0; }
	void stopD() { tmpspdd = spdd; spdd = 0; }
	void stopA() { tmpspda = spda; spda = 0; }
	void restoreSpdW() { spdw = 10; }
	void restoreSpdS() { spds = tmpspds; }
	void restoreSpdD() { spdd = tmpspdd; }
	void restoreSpdA() { spda = tmpspda; }*/
	void startUp() { up = true; }
	void startDown() { down = true; }
	void startLeft() { left = true; }
	void startRight() { right = true; }
	/*int getRx() { return rect.x; }
	int getRy() { return rect.y; }*/
	void color(int n1, int n2, int n3);
private:
	//SDL_Rect rect;
	//SDL_Texture* tex;
	/*SDL_Rect rect;*/
	/*bool damaged;
	int timer;*/
	bool up, down, left, right;
	int spdw, spds, spdd, spda;
	int tmpspdw, tmpspds, tmpspdd, tmpspda;
};

