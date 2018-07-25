#pragma once
#include"Enemy.h"

class Enemy;

class MovementBehavior
{
public:
	MovementBehavior();
	virtual void move(Enemy* e) = 0;
};

class ZombieBehavior: public MovementBehavior {
public:
	virtual void move(Enemy* e);
};

class GoblinBehavior: public MovementBehavior {
public:
	
	void move(Enemy*  e);
};

class WerewolfBehavior: public MovementBehavior {
public:
	void move(Enemy* e);
};


