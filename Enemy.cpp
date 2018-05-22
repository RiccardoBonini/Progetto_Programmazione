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
