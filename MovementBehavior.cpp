#include "MovementBehavior.h"

 MovementBehavior::MovementBehavior() {}

/*void ZombieBehavior::move(Enemy* e) {
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
	
}*/

 int ZombieBehavior::moveX(int coordX, int speed) {

	 if (coordX <= 500) {
		 int x = coordX + speed; 
		 return x;
	 }
	 else if(coordX >0){
		 int x = coordX - speed;
		 return x;
	 }
	
 }

 int ZombieBehavior::moveY(int coordY, int speed) {
	 return 0;
 }

 int GoblinBehavior::moveX(int coordX, int speed) {
 
	 int r = rand() % 2;
	 if (r == 0) {
		 int x = coordX + speed;
		 return x;
	 }
	 else {
		 int x = coordX - speed;
		 return x;
	 }
 
 }

 int GoblinBehavior::moveY(int coordY, int speed){
	 int r = rand() % 2;
	 if (r == 0) {
		 int x = coordY + speed;
		 return x;
	 }
	 else {
		 int x = coordY - speed;
		 return x;
	 }
 }

 int WerewolfBehavior::moveX(int coordX, int speed) {
	 return 0;
 }

 int WerewolfBehavior::moveY(int coordY, int speed) {
	 if (coordY <= 500) {
		 int x = coordY + speed;
		 return x;
	 }
	 else if (coordY >0) {
		 int x = coordY - speed;
		 return x;
	 }
 }
