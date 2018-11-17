#include "Enemy.h"
#include "Game.h"
#include "ItemFactory.h"

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
	damaged = true;
	SDL_SetTextureColorMod(tex, 255, 0, 0);
	//hp -= p.getDmg();
	alive = false;
}
void Enemy::update(){
	/*rect.h = 64;
	rect.w = 64;*/
	if (damaged == true) {
		if (timer < 50)
			timer++;
		else {
			timer = 0;
			damaged = false;
			SDL_SetTextureColorMod(tex, 255, 255, 255);
		}
	}
	move();
}


Goblin::Goblin(int bound1, int bound2) {
	erasable = false;
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
	timer = 0;
	damaged = false;
}

void Goblin::move()
{
	rect.x=this->behavior->moveX(rect.x, speed);
	rect.y = this->behavior->moveY(rect.y, speed);
}

Item* Goblin::drop() {
	return ItemFactory::createItem('f', rect.x, rect.y);
}

/*void Goblin::draw() {
	std::cout << "G";
}*/

Zombie::Zombie(int bound1, int bound2) {
	erasable = false;
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
	timer = 0;
	damaged = false;
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

Item* Zombie::drop() {
	return ItemFactory::createItem('p', rect.x, rect.y);
}

/*void Zombie::draw() {
	std::cout << "Z";
}*/

Werewolf::Werewolf(int bound1, int bound2) {
	erasable = false;
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
	timer = 0;
	damaged = false;
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

Item* Werewolf::drop() {
	return ItemFactory::createItem('b', rect.x, rect.y);
}

/*void Werewolf::draw() {
	std::cout << "W";
}*/