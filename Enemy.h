#pragma once
#include "Character.h"
#include "Projectile.h"
class Enemy:public Character
{
public:
	Enemy();
	~Enemy();
	void update();
	void getShot(Projectile *p);
	virtual void move()=0;
	static Enemy*makeEnemy(char choice);
};
class Goblin : public Enemy {
public:
	void move();
};
class Zombie : public Enemy {
public:
	void move();

};
class Werewolf : public Enemy {
public:
	void move();
};
