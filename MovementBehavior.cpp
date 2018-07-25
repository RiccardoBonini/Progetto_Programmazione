#include "MovementBehavior.h"

 MovementBehavior::MovementBehavior() {}

void ZombieBehavior::move(Enemy* e) {
	if (e->getX() != e->getXbound())
		e->setX(e->getX() + e->getSpd());
	else if (e->getX() == e->getXbound())
		e->setX(e->getX() - e->getSpd());
	else if (e->getX()==0)
		e->setX(e->getX() + e->getSpd());
	
}

void GoblinBehavior::move(Enemy* e) {
	int i = rand() % 100;
	int j = rand() % 100;
	if (i % 2 == 0) {
		if ((e->getX() != e->getXbound()))
			e->setX((e->getX() + e->getSpd()));
		if ((e->getX() == e->getXbound()))
			e->setX((e->getX() - e->getSpd()));
		if (j % 2 == 0) {
			if (e->getY() > 0)
				e->setY((e->getY() - e->getSpd()));
			if (e->getY() == 0)
				e->setY((e->getY() + e->getSpd()));
		}
		else {
			if (e->getY() < e->getYbound())
				e->setY((e->getY() + e->getSpd()));
			if (e->getY() == e->getYbound())
				e->setY((e->getY() - e->getSpd()));
		}
	}
	if (i % 2 != 0) {
		if (e->getX() != 0)
			e->setX((e->getX() - e->getSpd()));
		if ((e->getX() == 0))
			e->setX((e->getX() + e->getSpd()));
		if (j % 2 == 0) {
			if (e->getY() > 0)
				e->setY((e->getY() - e->getSpd()));
			if (e->getY() == 0)
				e->setY((e->getY() + e->getSpd()));
		}
		else {
			if (e->getY() < e->getYbound())
				e->setY((e->getY() + e->getSpd()));
			if (e->getY() == e->getYbound())
				e->setY((e->getY() - e->getSpd()));
		}
	}
}

void WerewolfBehavior::move(Enemy* e) {
	if ((e->getY() < e->getYbound()) && (e->getY() > 0) ) 
		e->incY(e->getSpd());			
	else if (e->getY() == e->getYbound())
		e->decY(e->getSpd());
	else if ( e->getY() == 0)
		e->incY( e->getSpd());
	
}
