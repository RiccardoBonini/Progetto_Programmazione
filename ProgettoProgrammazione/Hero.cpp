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
	handleInput();
	for (int i = 0; i < this->bullets.size(); i++)     //ciclo di aggiornamento dei proiettili
		bullets[i].update();
	
	
}

void Hero::getItem(Item item) {
	
    speed += item.getSpd();
	hp += item.getHp();
	damage += item.getDmg();

}

void Hero::getHit(Enemy enemy) {
	hp -= enemy.getDmg();
}

void Hero::shoot( bool Dir, bool Inc) {
	bullets.push_back(Bullet(this->getX(), this->getY(), Dir, Inc));

}

void Hero::handleInput() {

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_w:
			if(coordY!=0)
				coordY -= speed;
			break;
		case SDLK_s:
			if(coordY!=Ybound)
				coordY += speed;
			break;
		case SDLK_d:
			if(coordX!=Xbound)
				coordX += speed;
			break;
		case SDLK_a:
			if(coordX!=0)
				coordX -= speed;
			break;
		case SDLK_i:
			shoot( false, true);
			break;
		case SDLK_k:
			shoot( false, false);
			break;
		case SDLK_l:
			shoot(true, true);
			break;
		case SDLK_j:
			shoot( true, false);
			break;

		}
	}
}