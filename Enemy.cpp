#include "Enemy.h"
#include "Game.h"
#include "ItemFactory.h"

const float PI = 3.1415;

Enemy::Enemy(){}


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
	SDL_RenderCopy(Game::renderer, tex, &srect, &rect);
}

bool Enemy::HeroInSight(int x, int y)
{
	int distx = rect.x - x;
	int disty = rect.y - y;
	if (distx * distx + disty * disty  < sight * sight)
		return true;
	else
		return false;
}

void Enemy::getShot(Bullet p) {
	damaged = true;
	SDL_SetTextureColorMod(tex, 255, 0, 0);
	hp -= p.getDmg();
	if (hp<=0)
		alive = false;
}
void Enemy::update(Hero hero){
	
	if (damaged == true) {
		if (timer < 50)
			timer++;
		else {
			timer = 0;
			damaged = false;
			SDL_SetTextureColorMod(tex, 255, 255, 255);
		}
	}
	if (spotted == false && HeroInSight(hero.getRx(), hero.getRy()) == true)
		spotted = true;
	move(hero);
}


Goblin::Goblin(int x, int y) {
	erasable = false;
	hp = 50;
	speed = 2;
	damage = 500;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	tex = Game::LoadTexture("sprite/goblinsheet.png");
	this->behavior = new GoblinBehavior();
	srect.x = srect.y = 0;
	srect.h = 60;
	srect.w = 75;
	rect.x =x;
	rect.y =y;
	rect.h = 64;
	rect.w = 74;
	timer = 0;
	damaged = false;
	up = down = left = right = true;
	sight = 150;
	spotted = false;
}

void Goblin::move(Hero hero)
{
	this->behavior->move(*this, hero);
}

Item* Goblin::drop() {
	return ItemFactory::createItem('f', rect.x, rect.y);
}


Zombie::Zombie(int x, int y) {
	erasable = false;
	hp = 100;
	speed = 1;
	damage = 2;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	tex= Game::LoadTexture("sprite/zombiesheet.png");
	this->behavior = new ZombieBehavior;
	srect.x = srect.y = 0;
	srect.h = 84;
	srect.w = 60;
	rect.x = x;
	rect.y = y;
	rect.h = 80;
	rect.w = 60;
	timer = 0;
	damaged = false;
	up = down = left = right = true;
	direzione = 1;
	spotted = false;
	sight = 120;
}

void Zombie::move(Hero hero)
{
	
	this->behavior->move(*this, hero);
	
}

Item* Zombie::drop() {
	return ItemFactory::createItem('p', rect.x, rect.y);
}


Werewolf::Werewolf(int x, int y) {
	erasable = false;
	hp = 150;
	speed = 2;
	damage = 5;
	alive = true;
	coordX = rand() % 50;
	coordY = rand() % 10;
	tex= Game::LoadTexture("sprite/werewolfsheet.png");
	this->behavior = new WerewolfBehavior;
	srect.x = srect.y = 0;
	srect.h = 60;
	srect.w = 85;
	rect.x = x;
	rect.y = y;
	rect.h = 80;
	rect.w = 90;
	timer = 0;
	damaged = false;
	up = down = left = right = true;
	direzione = 1;
	spotted = false;
	sight = 200;
}

void Werewolf::move(Hero hero)
{
	
	this->behavior->move(*this, hero);
}

Item* Werewolf::drop() {
	return ItemFactory::createItem('b', rect.x, rect.y);
}

