#include "Projectile.h"



Projectile::Projectile(Character *hero, bool Dir, bool Inc)
{
	coordX = hero->getX();
	coordY = hero->getY();
	damage = hero->getDmg();
	dir = Dir;
	inc = Inc;
	//Ogni proiettile avrà due variabili che determinano lungo quale direzione si muove
	//e se tale direzione deve essere incrementata o decrementata
	//In questo modo nella funzione update() ogni proiettile verrà aggiornato secondo tali variabili
	//in maniera indipendente dagli altri 
}


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




