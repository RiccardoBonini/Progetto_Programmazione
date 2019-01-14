#include "Tile.h"
#include"Game.h"


Tile::~Tile()
{
}

void Tile::render() {
	SDL_RenderCopy(Game::renderer, tileTex, &srect, &rect);
}



Wall::Wall(int x, int y)
{
	tileTex = Game::LoadTexture("sprite/wall2.png");
	srect.x = srect.y = 0;
	srect.h = srect.w = 1000;
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;
	collision = true;
	breakable = false;
	spawn = false;
	erasable = false;
	posx = x;
	posy = y;
}


Ground::Ground(int x, int y, bool spn)
{
	tileTex = Game::LoadTexture("sprite/ground.png");
	srect.x = srect.y = 0;
	srect.h = srect.w = 500;
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;
	collision = false;
	spawn = spn;
	breakable = false;
	erasable = false;
	posx = x;
	posy = y;
}


void Tile::update() {
	
}

Pillar::Pillar(int x, int y)
{
	tileTex= Game::LoadTexture("sprite/pillar.png");
	srect.x = srect.y = 0;
	srect.h = 196;
	srect.w = 156;
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;
	spawn = false;
	collision = true;
	breakable = true;
	erasable = false;
	posx = x;
	posy = y;
}

Barrel::Barrel(int x, int y)
{
	tileTex = Game::LoadTexture("sprite/barrel.png");
	srect.x = srect.y = 0;
	srect.h = 230;
	srect.w = 150;
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;
	spawn = false;
	collision = true;
	breakable = true;
	erasable = false;
	posx = x;
	posy = y;
}
