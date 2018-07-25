#include "Bullet.h"
#include"TextureManager.h"


Bullet::Bullet(float X, float Y, bool Dir, bool Inc)
{
	coordX = X;
	coordY = Y;
	dir = Dir;
	inc = Inc;
	//Ogni proiettile avrà due variabili che determinano lungo quale direzione si muove
	//e se tale direzione deve essere incrementata o decrementata
	//In questo modo nella funzione update() ogni proiettile verrà aggiornato secondo tali variabili
	//in maniera indipendente dagli altri 
	rect.x = X;
	rect.y = Y;
	rect.h = rect.w = 32;
	if (Dir == true && Inc == true)
		bulletTex = TextureManager::LoadTexture("sprite/bullet2.png");
	else if (Dir == true && Inc == false)
		bulletTex = TextureManager::LoadTexture("sprite/bullet4.png");
	else if (Dir == false && Inc == true)
		bulletTex = TextureManager::LoadTexture("sprite/bullet1.png");
	else if (Dir == false && Inc == false)
		bulletTex = TextureManager::LoadTexture("sprite/bullet3.png");
}


Bullet::~Bullet()
{
}

void Bullet::update() {
	if (dir) {
		if (inc) {
			coordX++;
			rect.x+=1;
		}
		else {
			coordX--;
			rect.x -= 1;
		}
	}
	else {
		if (inc) {
			coordY--;
			rect.y -= 1;
		}
		else {
			coordY++;
			rect.y += 1;
		}
	}
		
}

void Bullet::render() {
	SDL_RenderCopy(Game::renderer, bulletTex, NULL, &rect);
	
}



