#pragma once
#include <SDL_ttf.h>
#include<SDL.h>
#undef main
#include <string>

class Text
{
public:
	Text();
	Text(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color,
		int h, int w, int x, int y, int timer);
	void display(SDL_Renderer *renderer);
	bool isErasable() { return erasable; }
	SDL_Texture *loadFont(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
	void updateTexture(SDL_Renderer *renderer, const std::string &font_path, int font_size, const std::string &message_text, const SDL_Color &color);
private:
	bool erasable;
	int timer;
	SDL_Texture * texture;
	SDL_Rect rect;
};

