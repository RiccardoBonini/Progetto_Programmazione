#include "Enemy.h"
#include "Game.h"

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

void Enemy::render(){
	SDL_RenderCopy(Game::renderer, tex, NULL, &rect);
}

void Enemy::getShot(Bullet p) {

	hp -= p.getDmg();
}
void Enemy::update(){
	/*rect.h = 64;
	rect.w = 64;*/
	//move();
}


Goblin::Goblin(int bound1, int bound2) {
	hp = 70;
	speed = 3.5;
	damage = 25;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 -2;
	Ybound = bound2 -2;
	tex = Game::LoadTexture("sprite/goblin.png");
	this->behavior = new GoblinBehavior();
	rect.x =2+ rand() %500;
	rect.y =2+ rand()% 500;
	rect.h = 64;
	rect.w = 64;
}

void Goblin::move()
{
	rect.x=this->behavior->moveX(rect.x, speed);
	rect.y = this->behavior->moveY(rect.y, speed);
}

/*void Goblin::draw() {
	std::cout << "G";
}*/

Zombie::Zombie(int bound1, int bound2) {
	hp = 150;
	speed = 10;
	damage = 50;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 -2;
	Ybound = bound2 -2;
	tex= Game::LoadTexture("sprite/zombie.png");
	this->behavior = new ZombieBehavior;
	rect.x = 2 + rand() % 500;
	rect.y = 2 + rand() % 500;
	rect.h = 64;
	rect.w = 64;
}

void Zombie::move()
{
	rect.x=this->behavior->moveX(rect.x, speed);
	/*if (coordX != Xbound)
		coordX += speed;
	else if(coordX == Xbound)
		coordX -= speed;
	else if (coordX == 0)
		coordX+= speed;
	else if(coordX != 0)
		coordY -= speed;*/
}

/*void Zombie::draw() {
	std::cout << "Z";
}*/

Werewolf::Werewolf(int bound1, int bound2) {
	hp = 200;
	speed = 2.5;
	damage = 50;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	Xbound = bound1 - 4;
	Ybound = bound2 -4;
	tex= Game::LoadTexture("sprite/werewolf.png");
	this->behavior = new WerewolfBehavior;
	rect.x = 2 + rand() % 500;
	rect.y = 2 + rand() % 500;
	rect.h = 64;
	rect.w = 64;
}

void Werewolf::move()
{
	rect.y=this->behavior->moveY(rect.y, speed);
	/*if (coordY != Ybound)
		coordY += speed;
	else if (coordY == Ybound)
		coordY -= speed;
	else if (coordY == 0)
		coordY += speed;
	else if (coordY != 0)
		coordY -= 0;*/
}

/*void Werewolf::draw() {
	std::cout << "W";
}*/