
#include "SDL.h"
#undef main
#include "Game.h"




Hero::Hero()
{
}

Hero::Hero(int x, int y)
{
	hp = 250;
	coordX = 0;
	coordY = 0;
	speed = 15;
	spdw =spds=spdd=spda = tmpspdw = tmpspds = tmpspdd = tmpspda = 10;
	damage = 30;
	alive = true;
	tex = Game::LoadTexture("sprite/knight.png");
	rect.h = 64;
	rect.w = 64;
	rect.x =x;
	rect.y =y;
	timer = 0;
	damaged = false;
	up = down = left = right = true;
	
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
			color(255, 255, 255);
		}
	}
	
	if (hp <= 0)
		alive = false;
	
	
}

void Hero::getItem(Item* item) {
	
    speed += item->getSpd();
	hp += item->getHp();
	damage += item->getDmg();

}

void Hero::getHit(Enemy* enemy) {
	damaged = true;
	color(255, 0, 0);
	hp -= enemy->getDmg();
}

void Hero::move(bool dir, bool inc) {
	if (dir == true) {
		if (inc == true) {
			{
			
			rect.x += speed;
		}
		}
		else {
			{
				
				rect.x -= speed;
			}
		}
	}
	else {
		if (inc == true) {
			 {
				
				rect.y -= speed;
			}
		}
		else {
			{
				
				rect.y += speed;
			}
		}
	}
}

void Hero::render() {

	
	SDL_RenderCopy(Game::renderer, tex, NULL, &rect);

}

void Hero::color(int n1, int n2, int n3) {

	SDL_SetTextureColorMod(tex, n1, n2, n3);
}
