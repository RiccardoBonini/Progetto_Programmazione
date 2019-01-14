#pragma once
#include"Enemy.h"

class Enemy;

class Hero;

class MovementBehavior
{
public:
	MovementBehavior();
	
	virtual void move(Enemy & enemy, Hero hero)=0;
};

class ZombieBehavior: public MovementBehavior {
public:
	
	void move(Enemy & enemy, Hero hero);
};

class GoblinBehavior: public MovementBehavior {
public:
	
	void move(Enemy & enemy, Hero hero);
};

class WerewolfBehavior: public MovementBehavior {
public:
	
	void move(Enemy & enemy, Hero hero);
};


