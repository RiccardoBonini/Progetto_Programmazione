#include "Tile.h"
#include"Game.h"

/*Tile::Tile()
{
}*/

Tile::~Tile()
{
}

void Tile::render() {
	SDL_RenderCopy(Game::renderer, tileTex, NULL, &rect);
}



Wall::Wall(int x, int y)
{
	tileTex = Game::LoadTexture("sprite/wall2.png");
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;
}

/*void Wall::render() {
SDL_RenderCopy(Game::renderer, tileTex, NULL, &rect);
}*/

Ground::Ground(int x, int y)
{
	tileTex = Game::LoadTexture("sprite/ground.png");
	rect.x = x;
	rect.y = y;
	rect.h = rect.w = 32;

}

/*void Ground::render() {
SDL_RenderCopy(Game::renderer, tileTex, NULL, &rect);
}*/

void Tile::update() {
	rect.h = 64;
	rect.w = 64;
}