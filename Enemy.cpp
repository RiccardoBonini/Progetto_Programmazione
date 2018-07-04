#include "Enemy.h"

Enemy::Enemy(){}

/*Enemy::Enemy(float bound1, float bound2)
{
	coordX = rand()% 50;
	coordY = rand()% 10;
	Xbound = bound1 - 4;
	Ybound = bound2 - 4;
}*/


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
void Enemy::move(){}

void Enemy::draw(){}

void Enemy::getShot(Bullet p) {

	hp -= p.getDmg();
}
void Enemy::update(){}

Enemy* Enemy::makeEnemy(char choice, float bound1, float bound2) {
	if (choice == 'g')
		return new Goblin(bound1, bound2);
	if (choice == 'z')
		return  new Zombie(bound1, bound2);
	if (choice == 'w')
		return  new Werewolf( bound1,  bound2);
}

Goblin::Goblin(float bound1, float bound2) {
	hp = 70;
	speed = 1;
	damage = 25;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 - 4;
	Ybound = bound2 - 4;
}

void Goblin::move()
{
	int i = rand() % 100;
	int j = rand() % 100;
	if (i % 2 == 0) {
		if (coordX != Xbound)
			coordX += speed;
		if (coordX == Xbound)
			coordX-=speed;
		if (j % 2 == 0) {
			if (coordY != 0)
				coordY -= speed;
			if (coordY == 0)
				coordY+= speed;
		}
		else {
			if (coordY != Ybound)
				coordY+= speed;
			if (coordY == Ybound)
				coordY-= speed;
		}
	}
	if (i % 2 != 0) {
		if (coordX != 0)
			coordX-= speed;
		if (coordX == 0)
			coordX+= speed;
		if (j % 2 == 0) {
			if (coordY != 0)
				coordY-= speed;
			if (coordY == 0)
				coordY+= speed;
		}
		else {
			if (coordY != Ybound)
				coordY+= speed;
			if (coordY == Ybound)
				coordY-= speed;
		}
	}
}

void Goblin::draw() {
	std::cout << "G";
}

Zombie::Zombie(float bound1, float bound2) {
	hp = 150;
	speed = 1;
	damage = 50;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 - 4;
	Ybound = bound2 - 4;
}

void Zombie::move()
{
	if (coordX != Xbound)
		coordX += speed;
	else if(coordX == Xbound)
		coordX -= speed;
	else if (coordX == 0)
		coordX+= speed;
	else if(coordX != 0)
		coordY -= speed;
}

void Zombie::draw() {
	std::cout << "Z";
}

Werewolf::Werewolf(float bound1, float bound2) {
	hp = 200;
	speed = 1;
	damage = 50;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 - 4;
	Ybound = bound2 - 4;
}

void Werewolf::move()
{
	if (coordY != Ybound)
		coordY += speed;
	else if (coordY == Ybound)
		coordY -= speed;
	else if (coordY == 0)
		coordY += speed;
	else if (coordY != 0)
		coordY -= 0;
}

void Werewolf::draw() {
	std::cout << "W";
}