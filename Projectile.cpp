#include "Projectile.h"



/*Projectile::Projectile(Hero *hero, bool Dir, bool Inc)
{
	coordX = hero->getX();
	coordY = hero->getY();
	damage = hero->getDmg();
	dir = Dir;
	inc = Inc;
}/**/


Projectile::~Projectile()
{
}

void Projectile::update() {
	if (dir == true) {
		if (inc)
			coordX++;
		else
			coordX--;

	}
	else {
		if (inc)
			coordY++;
		else
			coordY--;
	}
		
}




