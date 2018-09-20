#pragma once
#include"Enemy.h"

class Enemy;

class MovementBehavior
{
public:
	MovementBehavior();
	virtual int moveX(int coordX, int speed) = 0;
	virtual int moveY(int coordY, int speed) = 0;
};

class ZombieBehavior: public MovementBehavior {
public:
	virtual int moveX(int coordX, int speed);
	virtual int moveY(int coordY, int speed);
};

class GoblinBehavior: public MovementBehavior {
public:
	
	virtual int moveX(int coordX, int speed);
	virtual int moveY(int coordY, int speed);
};

class WerewolfBehavior: public MovementBehavior {
public:
	virtual int moveX(int coordX, int speed) ;
	virtual int moveY(int coordY, int speed) ;
};


