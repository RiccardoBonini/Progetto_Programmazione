#include "Enemy.h"

Enemy::Enemy(){}

Enemy::Enemy(float bound1, float bound2)
{
	coordX = rand()% 50;
	coordY = rand()% 10;
	Xbound = bound1 - 4;
	Ybound = bound2 - 4;
}


Enemy::~Enemy()
{
}

void Enemy::roam() {
	int i = rand() % 100;
	int j = rand() % 100;
	if (i%2 == 0) {
		if (coordX != Xbound)
			coordX++;
	    if(coordX == Xbound)
			coordX--;
		if (j%2== 0) {
			if (coordY != 0)
				coordY--;
			if (coordY == 0)
				coordY++;
		}
		else {
			if (coordY != Ybound)
				coordY++;
			if (coordY == Ybound)
				coordY--;
		}
	}
	if(i%2 !=0) {
		if (coordX != 0)
			coordX--;
		if (coordX == 0)
			coordX++;
		if (j%2 == 0) {
			if (coordY != 0)
				coordY--;
			if (coordY == 0)
				coordY++;
		}
		else {
			if (coordY != Ybound)
				coordY++;
			if (coordY == Ybound)
				coordY--;
		}
	}
}
/*void Enemy::move() {

}*/

void Enemy::getShot(Bullet p) {

	hp -= p.getDmg();
}
void Enemy::update(){}

Enemy* Enemy::makeEnemy(char choice) {
	if (choice == 'g')
		return new Goblin;
	if (choice == 'z')
		return new Zombie;
	if (choice == 'w')
		return new Werewolf;
}

Goblin::Goblin() {
	hp = 70;
	speed = 4;
	damage = 25;
	alive = true;
}

void Goblin::move()
{
}

Zombie::Zombie() {
	hp = 150;
	speed = 1;
	damage = 50;
	alive = true;
}

void Zombie::move()
{
}
 
Werewolf::Werewolf() {
	hp = 200;
	speed = 3;
	damage = 50;
	alive = true;
}

void Werewolf::move()
{
}
