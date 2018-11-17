#include "Item.h"
#include"Game.h"


Item::Item(){
}

Item::~Item()
{
}

void Item::render() {
	SDL_RenderCopy(Game::renderer, tex, NULL, &rect);
}

Potion::Potion(int x, int y) {
	hpValue = 50;
	damageValue = 0;
	speedValue = 0;
	erasable = false;
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;
	tex = Game::LoadTexture("sprite/potion.png");
}

Bazooka::Bazooka(int x, int y) {
	hpValue = 0;
	damageValue = 25;
	speedValue = 0;
	erasable = false;
	rect.x = x;
	rect.y = y;
	rect.h = 48;
	rect.w = 64;
	tex = Game::LoadTexture("sprite/bazooka.png");
}

MightyFork::MightyFork(int x, int y) {
	hpValue = 250;
	damageValue = 150;
	speedValue = 5;
	erasable = false;
	rect.x = x;
	rect.y = y;
	rect.h = 32;
	rect.w = 48;
	tex = Game::LoadTexture("sprite/fork.png");
}

