#include "Hero.h"
#include "SDL.h"


Hero::Hero()
{
	hp = 500;
	coordX = 0;
	coordY = 0;
	speed = 1;
	alive = true;
}

Hero::~Hero()
{
}

void Hero::update(){
	if (hp == 0)
		alive = false;
	handleInput();
	
	//stampa di verifica delle coordinate
	std::cout << coordX << "  " << coordY << std::endl;

}

void Hero::getItem(Item *item) {
	
    speed += item->getSpd();
	hp += item->getHp();
	damage += item->getDmg();

}

void Hero::getHit(Character* enemy) {
	hp -= enemy->getDmg();
}

void Hero::handleInput() {

	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_w:
			coordY += speed;
			break;
		case SDLK_s:
			coordY -= speed;
			break;
		case SDLK_d:
			coordX += speed;
			break;
		case SDLK_a:
			coordX -= speed;
			break;
		case SDLK_i:
			//spara in alto
			break;
		case SDLK_k:
			//spara in basso
			break;
		case SDLK_l:
			//spara a destra
			break;
		case SDLK_j:
			//spara a sinistra
			break;

		}
	}
}