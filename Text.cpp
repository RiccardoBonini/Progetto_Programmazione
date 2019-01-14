#include "Text.h"
#include <iostream>

Text::Text()
{
}

Text::Text(SDL_Renderer * renderer, const std::string & font_path, int font_size, const std::string & message_text, const SDL_Color & color,
	int h, int w, int x, int y,int timer)
{
	texture = loadFont(renderer, font_path, font_size, message_text, color);
	SDL_QueryTexture(texture, nullptr, nullptr, &rect.w, &rect.h);
	rect.h = h;
	rect.w = w;
	rect.x = x;
	rect.y = y;
	this->timer = timer;
	erasable = false;
}

void Text::display(SDL_Renderer * renderer)
{
	SDL_RenderCopy(renderer, texture, nullptr, &rect);
	if (timer > 0)
		rect.x++;
	timer--;
	if (timer == 1)
		erasable = true;
}

SDL_Texture * Text::loadFont(SDL_Renderer * renderer, const std::string & font_path, int font_size, const std::string & message_text, const SDL_Color & color)
{
	TTF_Font *font = TTF_OpenFont(font_path.c_str(), font_size);
	if (font == 0) {
		std::cout << "load font error " << std::endl;
	}
	SDL_Surface *text_surface =  TTF_RenderText_Solid(font, message_text.c_str(), color);
	if (!text_surface) {
		std::cout << "text surface error " << std::endl;
	}
	SDL_Texture *text_texture = SDL_CreateTextureFromSurface(renderer, text_surface);
	if (!text_texture) {
		std::cout << "text texture error " << std::endl;
	}
	SDL_FreeSurface(text_surface);
	return text_texture;

}

void Text::updateTexture(SDL_Renderer * renderer, const std::string & font_path, int font_size, const std::string & message_text, const SDL_Color & color)
{
	texture = loadFont(renderer, font_path, font_size, message_text, color);
}
