#include "TextureManager.h"



SDL_Texture* TextureManager::LoadTexture(const char* sprite) {

	SDL_Surface* tmpSurface = IMG_Load(sprite);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void TextureManager::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}