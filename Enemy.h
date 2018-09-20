#pragma once
#include "Character.h"
#include "Bullet.h"
#include "MovementBehavior.h"

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
	virtual void render();
	virtual void move() = 0;
protected:
	MovementBehavior* behavior;
	//SDL_Texture* tex;
	//SDL_Rect rect;
	/*float Xbound;
	float Ybound;*/
};

class Goblin : public Enemy {
public:
	Goblin(int bound1, int bound2);
	void move();
	//void render();

	
};

class Zombie : public Enemy {
public:
	Zombie(int bound1, int bound2);
    void move();
	//void render();

};

class Werewolf : public Enemy {
public:
	Werewolf(int bound1, int bound2);
	void move();
	//void render();

};
