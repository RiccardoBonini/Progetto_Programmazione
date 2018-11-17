
#include "SDL.h"
#include "Game.h"


Hero::Hero() {

}

Hero::Hero(float bound1, float bound2)
{
	hp = 250;
	coordX = 0;
	coordY = 0;
	speed = 15;
	spdw =spds=spdd=spda = tmpspdw = tmpspds = tmpspdd = tmpspda = 10;
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
	/*rect.h = 64;
	rect.w = 64;*/
	
}

void Hero::getItem(Item* item) {
	
    speed += item->getSpd();
	hp += item->getHp();
	damage += item->getDmg();

}

void Hero::getHit(Enemy* enemy) {
	damaged = true;
	color(255, 0, 0);
	//hp -= enemy->getDmg();
}

void Hero::move(bool dir, bool inc) {
	if (dir == true) {
		if (inc == true) {
			{
			//coordX += speed / 10;
			rect.x += speed;
		}
		}
		else {
			{
				//coordX -= speed / 10;
				rect.x -= speed;
			}
		}
	}
	else {
		if (inc == true) {
			 {
				//coordY -= speed / 10;
				rect.y -= speed;
			}
		}
		else {
			{
				//coordY += speed / 10;
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
