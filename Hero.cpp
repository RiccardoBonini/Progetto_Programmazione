#include "Hero.h"
#include "SDL.h"

Hero::Hero() {}

Hero::Hero(float bound1, float bound2)
{
	hp = 250;
	coordX = 0;
	coordY = 0;
	speed = 1;
	damage = 30;
	alive = true;
	Xbound = bound1 -4;
	Ybound = bound2 - 2;
}

Hero::~Hero()
{
}

void Hero::update(){
	if (hp == 0)
		alive = false;
	
}

void Hero::getItem(Item item) {
	
    speed += item.getSpd();
	hp += item.getHp();
	damage += item.getDmg();

}

/*void Hero::getHit(Enemy enemy) {
	hp -= enemy.getDmg();
}*/

void Hero::move(bool dir, bool inc) {
	if (dir == true) {
		if (inc == true) {
			if (coordX != Xbound)
				coordX += speed;
		}
		else {
			if (coordX != 0)
				coordX -= speed;
		}
	}
	else {
		if (inc == true) {
			if (coordY != 0)
				coordY -= speed;
		}
		else {
			if (coordY != Ybound)
				coordY += speed;
		}
	}
}