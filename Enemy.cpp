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

void Enemy::draw(){}

void Enemy::getShot(Bullet p) {

	hp -= p.getDmg();
}
void Enemy::update(){}


Goblin::Goblin(int bound1, int bound2) {
	hp = 70;
	speed = 1;
	damage = 25;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 -2;
	Ybound = bound2 -2;
	
	this->behavior = new GoblinBehavior();
}

void Goblin::move()
{
	this->behavior->move(this);
}

void Goblin::draw() {
	std::cout << "G";
}

Zombie::Zombie(int bound1, int bound2) {
	hp = 150;
	speed = 1;
	damage = 50;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 -2;
	Ybound = bound2 -2;
	
	this->behavior = new ZombieBehavior;
}

void Zombie::move()
{
	this->behavior->move(this);
	/*if (coordX != Xbound)
		coordX += speed;
	else if(coordX == Xbound)
		coordX -= speed;
	else if (coordX == 0)
		coordX+= speed;
	else if(coordX != 0)
		coordY -= speed;*/
}

void Zombie::draw() {
	std::cout << "Z";
}

Werewolf::Werewolf(int bound1, int bound2) {
	hp = 200;
	speed = 1;
	damage = 50;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 - 4;
	Ybound = bound2 -4;
	
	this->behavior = new WerewolfBehavior;
}

void Werewolf::move()
{
	this->behavior->move(this);
	/*if (coordY != Ybound)
		coordY += speed;
	else if (coordY == Ybound)
		coordY -= speed;
	else if (coordY == 0)
		coordY += speed;
	else if (coordY != 0)
		coordY -= 0;*/
}

void Werewolf::draw() {
	std::cout << "W";
}