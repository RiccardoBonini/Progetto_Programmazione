
#include "SDL.h"
#include "Game.h"


Hero::Hero() {

}

Hero::Hero(float bound1, float bound2)
{
	hp = 250;
	coordX = 0;
	coordY = 0;
	speed = 35;
	damage = 30;
	alive = true;
	Xbound = bound1 ;
	Ybound = bound2 ;
	tex = Game::LoadTexture("sprite/knight.png");
	rect.h = 64;
	rect.w = 64;
	rect.x =120;
	rect.y =60;
	timer = 0;
	damaged = false;
}

Hero::~Hero()
{
}

void Hero::update(){
	if (damaged== true) {
		if (timer < 50 )
			timer++;
		else {
			timer = 0;
			damaged = false;
			SDL_SetTextureColorMod(tex, 255, 255, 255);
		}
	}
	
	if (hp <= 0)
		alive = false;
	/*rect.h = 64;
	rect.w = 64;*/
	
}

void Hero::getItem(Item item) {
	
    speed += item.getSpd();
	hp += item.getHp();
	damage += item.getDmg();

}

void Hero::getHit(Enemy* enemy) {
	damaged = true;
	SDL_SetTextureColorMod(tex, 255, 0, 0);
	//hp -= enemy->getDmg();
}

void Hero::move(bool dir, bool inc) {
	if (dir == true) {
		if (inc == true) {
			/*if (coordX != Xbound)*/ {
			coordX += speed / 10;
			rect.x += speed;
		}
		}
		else {
			/*if (coordX != 0)*/ {
				coordX -= speed / 10;
				rect.x -= speed;
			}
		}
	}
	else {
		if (inc == true) {
			/*if (coordY != 0) */{
				coordY -= speed / 10;
				rect.y -= speed;
			}
		}
		else {
			/*if (coordY != Ybound)*/ {
				coordY += speed / 10;
				rect.y += speed;
			}
		}
	}
}

void Hero::render() {

	SDL_RenderCopy(Game::renderer, tex, NULL, &rect);

}