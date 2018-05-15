#include "Hero.h"
#include "SDL.h"


Hero::Hero()
{
	hp = 500;
	coordX = 0;
	coordY = 0;
	speed = 1;
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

/*void Hero::getHit(Enemy* enemy) {
	hp -= enemy->getDmg();
}*/

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
			std::cout << "pew pew alto" << std::endl;
			break;
		case SDLK_k:
			//spara in basso
			std::cout << "pew pew basso" << std::endl;
			break;
		case SDLK_l:
			//spara a destra
			std::cout << "pew pew dx" << std::endl;
			break;
		case SDLK_j:
			//spara a sinistra
			std::cout << "pew pew sx" << std::endl;
			break;

		}
	}
}