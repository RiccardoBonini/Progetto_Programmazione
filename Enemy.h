#pragma once
#include "Character.h"
#include "Bullet.h"
#include "MovementBehavior.h"
#include "Item.h"
#include "Hero.h"

class MovementBehavior;



class Enemy:public Character
{
public:
	Enemy();
	~Enemy();
	void update(Hero hero);
	void getShot(Bullet p);
	void die() { coordX = -1; coordX = -1; Xbound = 0; Ybound = 0; }
	void roam();
    void render();
	void erase() { erasable = true; }
	bool isErasable() { return erasable; }
	virtual void move(Hero hero) = 0;
	virtual Item* drop() = 0;
	MovementBehavior * getBehavior() { return behavior; }
	void setUp(bool dir) { up = !dir; }
	void setDown(bool dir){ down = !dir; }
	void setRight(bool dir) { right = !dir; }
	void setLeft(bool dir) { left = !dir; }
	bool getUp() { return up; }
	bool getDown() { return down; }
	bool getRight() { return right; }
	bool getLeft() { return left; }
	int getDirezione() { return direzione; }
	void setDirezione(int i) { direzione = i; }
	bool HeroInSight(int x, int y);
	bool HeroIsSpotted() { return spotted; }
protected:
	MovementBehavior* behavior;
	bool erasable;
	bool up, down, left, right;
	int direzione;
	bool spotted;
	int sight;
	
};

class Goblin : public Enemy {
public:
	Goblin(int x, int y);
	void move(Hero hero);
	Item* drop();
	
	
};

class Zombie : public Enemy {
public:
	Zombie(int x, int y);
    void move(Hero hero);
	Item* drop();

};

class Werewolf : public Enemy {
public:
	Werewolf(int x, int y);
	void move(Hero hero);
	Item* drop();
	
};
