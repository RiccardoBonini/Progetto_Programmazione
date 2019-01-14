#pragma once
#include "Game.h"
class Observer
{
	Game *target;
public:
	Observer(Game *targ) { target = targ; target->attach(this); }
	virtual void update() = 0;
protected:
	Game * getTarget() { return target; }
	
};

class ScoreObserver : public Observer
{
public:
	ScoreObserver(Game* targ) : Observer(targ) {}
	void update();
};

class SurroundingObserver : public Observer
{
public:
	SurroundingObserver(Game* targ) : Observer(targ) {}
	void update();
};


