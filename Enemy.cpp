#include "Enemy.h"



Enemy::Enemy()
{
}


Enemy::~Enemy()
{
}

void Enemy::move() {

}

void Enemy::getShot(Projectile *p) {

	hp -= p->getDmg();
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
 