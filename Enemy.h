#pragma once
#include "Character.h"
#include "Bullet.h"
#include "MovementBehavior.h"
#include "Item.h"

class MovementBehavior;

class Enemy:public Character
{
public:
	Enemy();
	~Enemy();
	void update();
	void getShot(Bullet p);
	void die() { coordX = -1; coordX = -1; Xbound = 0; Ybound = 0; }
	void roam();
    void render();
	void erase() { /*rect.x = rect.y = NULL; rect.h = rect.w = 0;*/ erasable = true; }
	bool isErasable() { return erasable; }
	virtual void move() = 0;
	virtual Item* drop() = 0;
protected:
	MovementBehavior* behavior;
	bool erasable;
	//SDL_Texture* tex;
	//SDL_Rect rect;
	/*float Xbound;
	float Ybound;*/
};

class Goblin : public Enemy {
public:
	Goblin(int bound1, int bound2);
	void move();
	Item* drop();
	//void render();

	
};

class Zombie : public Enemy {
public:
	Zombie(int bound1, int bound2);
    void move();
	Item* drop();
	//void render();

};

class Werewolf : public Enemy {
public:
	Werewolf(int bound1, int bound2);
	void move();
	Item* drop();
	//void render();

};
