#pragma once
#include "Character.h"
#include "Bullet.h"
class Enemy:public Character
{
public:
	Enemy();
	~Enemy();
	void update();
	void getShot(Bullet p);
	void die() { coordX = -1; coordX = -1; Xbound = 0; Ybound = 0; }
	void roam();
	virtual void draw() = 0;
	virtual void move()=0;
	static Enemy* makeEnemy(char choice, float bound1, float bound2);
protected:
	float Xbound;
	float Ybound;
};

class Goblin : public Enemy {
public:
	Goblin(float bound1, float bound2);
	void move();
	void draw();
};

class Zombie : public Enemy {
public:
	Zombie(float bound1, float bound2);
    void move();
	void draw();
};

class Werewolf : public Enemy {
public:
	Werewolf(float bound1, float bound2);
	void move();
	void draw();
};
