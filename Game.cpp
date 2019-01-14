#include "Game.h"
#include "Observer.h"



SDL_Renderer* Game::renderer = nullptr;


Game::Game(int num)
{
	enemiesNum = num;
}

Game::~Game()
{
}

void Game::init(const char *title, int x, int y, int width, int height, bool fullscreen) {
	
	int screen = 0;
	if (fullscreen == true)
		screen = SDL_WINDOW_FULLSCREEN;
	if(SDL_Init(SDL_INIT_EVERYTHING)==0){
	window = SDL_CreateWindow(title, x, y, width, height, screen);
	renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);}
	isRunning = true;
	if (TTF_Init() == -1)
		isRunning = false;
	item ;
	room = Map();
	room.loadMap();
	hero= Hero(120, 60);
	room.spawnEnemies(enemies, enemiesNum);
	deadEnemies = 0;
	brokenThings = 0;
	timer = 0;
	strike = false;
	firstStrike = false;
	firstMassacre = false;
	firstVandal = false;
	sob = new ScoreObserver(this);
	aob = new SurroundingObserver(this);
	lastdir = 0;
	punteggio = Text(Game::renderer, "sprite/arial.ttf", 30, "Punteggio : ", { 0, 0, 0, 0 }, 100, 200, 50, 650, 0);
	victory = Text(Game::renderer, "sprite/arial.ttf", 30, "VICTORY", { 255, 0, 0, 0 }, 300, 600, 350, 200, 0);
	lost = Text(Game::renderer, "sprite/arial.ttf", 30, "YOU LOST", { 0, 0, 255, 0 }, 300, 600, 350, 200, 0);
	pressanykey = Text(Game::renderer, "sprite/arial.ttf", 30, "press H to exit the game", { 0, 0, 0, 0 }, 100, 400, 450, 500, 0);
	for (int i = 0; i < enemiesNum + 1; i++)
		score.push_back(Text(Game::renderer, "sprite/arial.ttf", 30, std::to_string(i), { 0, 0, 0, 0 }, 100, 20, 255, 650, 0));
	end = false;
	
}

void Game::handleExit(){
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	
	}
	
}

void Game::handleInput() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_ESCAPE:
			isRunning = false;
			break;
		case SDLK_w:
	      
			if (room.CollisionCWup(hero.getRx(), hero.getRy(), hero.getRw(), hero.getRh(), hero.getSpd()) == false) {
				hero.move(false, true);
				room.adjustY(hero.getSpd());
				adjustY(hero.getSpd());
				lastdir = 1;
				break;
			}
			else {
				room.setUp(hero);
				break;
			}
			break;
		case SDLK_s:
			
			if (room.CollisionCWdown(hero.getRx(), hero.getRy(), hero.getRw(), hero.getRh(), hero.getSpd()) == false) {
				hero.move(false, false);
				room.adjustY(-hero.getSpd());
				adjustY(-hero.getSpd());
				lastdir = 2;
				break;
			}
			else if (room.CollisionCWdown(hero.getRx(), hero.getRy(), hero.getRw(), hero.getRh(), hero.getSpd()) == true) {
				room.setDown(hero);
				break;
			}
			break;
		case SDLK_d:
			
			if (room.CollisionCWright(hero.getRx(), hero.getRy(), hero.getRw(), hero.getRh(), hero.getSpd()) == false) {
				hero.move(true, true);
				room.adjustX(-hero.getSpd());
				adjustX(-hero.getSpd());
				lastdir = 3;
				break;
			}
			else {
				room.setRight(hero);
				break;
			}
			break;
		case SDLK_a:
			
			if (room.CollisionCWleft(hero.getRx(), hero.getRy(), hero.getRw(), hero.getRh(), hero.getSpd()) == false) {
				hero.move(true, false);
				room.adjustX(hero.getSpd());
				adjustX(hero.getSpd());
				lastdir = 4;
				break;
			}
			else {
				room.setLeft(hero);
				break;
			}
			break;
		case SDLK_i:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), false, true));
			break;
		case SDLK_k:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), false, false));
			break;
		case SDLK_l:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), true, true));
			break;
		case SDLK_j:
			bullets.push_back(Bullet(hero.getRx(), hero.getRy(), true, false));
			break;
		case SDLK_h:
			if (end == true)
				isRunning = false;
			break;
		}
	}
}

void Game::update() {

	room.update();
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
		for (int j = 0; j < enemies.size(); j++) {
			if (CollisionB(enemies[j], bullets[i])) {
				enemies[j]->getShot(bullets[i]);
				if (enemies[j]->isAlive() == false) {
					items.push_back(enemies[j]->drop());
					enemies[j]->erase();
					deadEnemies++;
				}
				bullets[i].eraseBullet();
			}
			
	
		}
		

	}
	room.CollisionBW(bullets, brokenThings);
	
	for (int j = 0; j < enemies.size(); j++) {
		if (CollisionC(hero, enemies[j]))
			hero.getHit(enemies[j]);
		enemies[j]->setUp(room.CollisionCWup(enemies[j]->getRx(), enemies[j]->getRy(), enemies[j]->getRw(), enemies[j]->getRh(), enemies[j]->getSpd()));
		enemies[j]->setDown(room.CollisionCWdown(enemies[j]->getRx(), enemies[j]->getRy(), enemies[j]->getRw(), enemies[j]->getRh(), enemies[j]->getSpd()));
		enemies[j]->setRight(room.CollisionCWright(enemies[j]->getRx(), enemies[j]->getRy(), enemies[j]->getRw(), enemies[j]->getRh(), enemies[j]->getSpd()));
		enemies[j]->setLeft(room.CollisionCWleft(enemies[j]->getRx(), enemies[j]->getRy(), enemies[j]->getRw(), enemies[j]->getRh(), enemies[j]->getSpd()));
		enemies[j]->update(hero);
	}
	
	for (int i = 0; i < items.size();i++) {
		if (CollisionHI(hero, items[i])) {
			hero.getItem(items[i]);
			items[i]->erase();
			
		}

		
	}
	
	hero.update();
	notify();
	if (strike == true) {
		if (timer < 150)
			timer++;
		else {
			timer = 0;
			strike = false;
			hero.color(255, 255, 255);
		}
	}


	for (int i = 0; i < bullets.size(); i++) {       //ciclo di cancellazione degli elementi "erasable"
		if (bullets[i].isErasable())
			bullets.erase(bullets.begin() + i);
	}
	
	for (int i = 0; i < enemies.size(); i++) {
		if (enemies[i]->isErasable())
			enemies.erase(enemies.begin() + i);
	}

	for (int i = 0; i < items.size(); i++) {
		if (items[i]->isErasable())
			items.erase(items.begin() + i);
	}

	for (int i = 0; i < text.size(); i++) {
		if (text[i].isErasable())
			text.erase(text.begin() + i);
	}

	room.erase();
	if (deadEnemies >= 6 || hero.isAlive() == false)
		end = true; 
}

void Game::render() {
	SDL_RenderClear(renderer);
	if (end == false) {
		room.drawMap();
		hero.render();
		for (int j = 0; j < enemies.size(); j++)
			enemies[j]->render();

		for (int j = 0; j < bullets.size(); j++)
			bullets[j].render();

		for (int i = 0; i < items.size(); i++)
			items[i]->render();
		
		for (int i = 0; i < text.size(); i++) {
			text[i].display(renderer);

		}
		punteggio.display(renderer);
		score[deadEnemies].display(renderer);
	}
	else {
		SDL_RenderClear(renderer);
		if (deadEnemies >= 5) {
			victory.display(renderer);
			pressanykey.display(renderer);
		}
		else {
			lost.display(renderer);
			pressanykey.display(renderer);
		}
		
	}
	SDL_RenderPresent(renderer);
	
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	TTF_Quit();
	SDL_Quit();
}

SDL_Texture* Game::LoadTexture(const char* sprite) {

	SDL_Surface* tmpSurface = IMG_Load(sprite);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);

	return texture;
}

void Game::draw(SDL_Texture* tex, SDL_Rect src, SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

bool Game::CollisionC(Character a, Character* b) {
	if (a.getRx() + a.getRw()/2 < b->getRx() || a.getRx() > b->getRx() + b->getRw()/2 ||
		a.getRy() + a.getRh()/2 < b->getRy() || a.getRy() > b->getRy() + b->getRh()/2)
		return false;
	else
		return true;
}

bool Game::CollisionB(Character*a, Bullet b) {
	if (a->getRx() + a->getRw()  < b.getRx() || a->getRx() > b.getRx() + b.getRw()  ||
		a->getRy() + a->getRh()  < b.getRy() || a->getRy() > b.getRy() + b.getRh() )
		return false;
	else
		return true;
}


bool Game::CollisionHI(Character a, Item * b)
{
	if (a.getRx() + a.getRw() < b->getRx() || a.getRx() > b->getRx() + b->getRw() ||
		a.getRy() + a.getRh() < b->getRy() || a.getRy() > b->getRy() + b->getRh() )
		return false;
	else
		return true;
}


void Game::notify() {
	for (int i = 0; i < observer.size(); i++)
		observer[i]->update();
}

void Game::attach(Observer* ob) {
	observer.push_back(ob);
}

void Game::deadStrike() {
	if (firstStrike == false) {
		hero.color(36, 23, 157); 
		text.push_back(Text(Game::renderer, "sprite/arial.ttf", 30, "KILL STREAK!" , { 0, 0, 255, 0 }, 100, 200, hero.getRx() -150, hero.getRy() - 100, 150));
		strike = true;
	}
	firstStrike = true;
}

void Game::massacre()
{
	if (firstMassacre == false) {
		hero.color(36, 23, 157);
		text.push_back(Text(Game::renderer, "sprite/arial.ttf", 30, "MASSACRE!", { 0, 255, 255, 0 }, 100, 200, hero.getRx() - 150, hero.getRy() - 100, 150));
		strike = true;
	}
	firstMassacre = true;
}

void Game::vandal()
{
	if (firstVandal == false) {
		hero.color(36, 23, 157);
		text.push_back(Text(Game::renderer, "sprite/arial.ttf", 30, "VANDAL!", { 255, 0, 0, 0 }, 100, 200, hero.getRx() - 150, hero.getRy() - 100, 150));
		strike = true;
	}
	firstVandal = true;

}

void Game::adjustX(int speed) {
	for (int i = 0; i < enemies.size(); i++)
		enemies[i]->setRx(enemies[i]->getRx() + speed);
	for (int j = 0; j < items.size(); j++)
		items[j]->setRx(items[j]->getRx() + speed);
}

void Game::adjustY(int speed) {
	for (int i = 0; i < enemies.size(); i++)
		enemies[i]->setRy(enemies[i]->getRy() + speed);
	for (int j = 0; j < items.size(); j++)
		items[j]->setRy(items[j]->getRy() + speed);
}

