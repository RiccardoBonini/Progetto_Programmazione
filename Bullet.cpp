#include "Bullet.h"



Bullet::Bullet(float X, float Y, bool Dir, bool Inc)
{
	coordX = X;
	coordY = Y;
	dir = Dir;
	inc = Inc;
	//Ogni proiettile avrà due variabili che determinano lungo quale direzione si muove
	//e se tale direzione deve essere incrementata o decrementata
	//In questo modo nella funzione update() ogni proiettile verrà aggiornato secondo tali variabili
	//in maniera indipendente dagli altri 
}


Bullet::~Bullet()
{
}

void Bullet::update() {
	if (dir) {
		if (inc)
			coordX++;
		else
			coordX--;
	}
	else {
		if (inc)
			coordY--;
		else
			coordY++;
	}
		
}




