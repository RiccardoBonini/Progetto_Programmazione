#pragma once
#include "Character.h"
#include "Bullet.h"
class Enemy:public Character
{
public:
	Enemy();
	Enemy(float bound1, float bound2);
	~Enemy();
	void update();
	void getShot(Bullet p);
	void die() { coordX = -1; coordX = -1; Xbound = 0; Ybound = 0; }
	void roam();
	//virtual void move()=0;
	static Enemy*makeEnemy(char choice);
private:
	float Xbound;
	float Ybound;
};

class Goblin : public Enemy {
public:
	Goblin();
	void move();
};

class Zombie : public Enemy {
public:
	Zombie();
    void move();

};

class Werewolf : public Enemy {
public:
	Werewolf();
	void move();
};
