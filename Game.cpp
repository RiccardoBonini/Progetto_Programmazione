#include "Game.h"
#include "Observer.h"

SDL_Renderer* Game::renderer = nullptr;

Game::Game(int num1, int num2, int num3)
{
	goblinNum = num1;
	zombieNum = num2;
	werewolfNum = num3;

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
	item ;
	//room.loadMap();
	/*for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++)
			map[i][j] = room.loadMap(i, j);
	}
	//inserimento tiles nel vettore. In questo modo il rendering richiede solo di disegnare i singoli tiles
	//int muro = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			int muro = map[i][j];
			int x = j * 32;
			int y = i * 32;
			if (muro == 1)
				tiles.push_back(TileFactory::makeTile('w', x, y));
			//SDL_RenderCopy(Game::renderer, wall, NULL, &dest);
			//TextureManager::draw(wall, src, dest);
			else if (muro == 0)
				tiles.push_back(TileFactory::makeTile('g', x, y));
			//SDL_RenderCopy(Game::renderer, terrain, NULL, &dest);
			//TextureManager::draw(terrain, src, dest);
			else
				break;
		}
	}*/
	roomWidth = room.getWidth();
	roomHeight = room.getHeight();
	for (int i = 0; i < 2 /*goblinNum*/; i++)
		enemies.push_back(EnemyFactory::makeEnemy('g',roomWidth, roomHeight));
	for (int i = 0; i < 2/*zombieNum*/; i++)
		enemies.push_back(EnemyFactory::makeEnemy('z', roomWidth, roomHeight));
	for (int i = 0; i < 2 /*werewolfNum*/; i++)
		enemies.push_back(EnemyFactory::makeEnemy('w', roomWidth, roomHeight));
	room = Map();
	room.loadMap();
	hero= Hero(room.getWidth(), room.getHeight());
	solidSize = room.mapSize();
	deadEnemies = 0;
	timer = 0;
	strike = false;
	firstStrike = false;
	sob = new ScoreObserver(this);
	lastdir = 0;
	
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

		}
	}
}

void Game::update() {
	//room.update();
	/*for (int i = 0; i < solidSize; i++) {
		if (room.getTile(i)->solid() == true) {
			if (CollisionWup(hero, room.getTile(i))==true)
				hero.setUp(false);
			else
				hero.setUp(true);
			if (CollisionWdown(hero, room.getTile(i))==true)
				hero.setDown(false);
			else
				hero.setDown(true);
			if (CollisionWleft(hero, room.getTile(i))==true)
				hero.setLeft(false);
			else
				hero.setLeft(true);
			if (CollisionWright(hero, room.getTile(i))==true)
				hero.setRight(false);
			else
				hero.setRight(true);
		}
	}*/
	/*for (int i = 0; i < solidSize; i++) {
		if (room.solidTile(i) == true) {
			/*if (CollisionW(hero, room.getTile(i)) && under(hero, room.getTile(i)))
				//hero.getHit(enemies[1]);
				hero.stopUp();
			/*if (CollisionW(hero, room.getTile(i)) && over(hero, room.getTile(i)))
				hero.stopDown();
			if (CollisionW(hero, room.getTile(i)) && left(hero, room.getTile(i)))
				hero.stopRight();
			if (CollisionW(hero, room.getTile(i)) && right(hero, room.getTile(i)))
				hero.stopLeft();*/
			/*for (int j = 0; j < bullets.size(); j++) {
				if (room.CollisionBW(bullets[j]))
					bullets[j].erase();
			}*/
		
		/*else if(room.solidTile(i)==false){
			//if(CollisionW(hero, room.getTile(i))==true)
				if(hero.getUp()==false || hero.getDown()==false || hero.getLeft()==false || hero.getRight()==false)
					hero.free();
			  //hero.getHit(enemies[1]);
		}*/
		
	//}
	for (int i = 0; i < bullets.size(); i++) {
		bullets[i].update();
		for (int j = 0; j < enemies.size(); j++) {
			if (CollisionB(enemies[j], bullets[i])) {
				enemies[j]->getShot(bullets[i]);
				if (enemies[j]->isAlive() == false) {
					items.push_back(enemies[j]->drop());
					enemies[j]->erase();
					//enemies.erase(enemies.begin() + j );
					deadEnemies++;
				}
				bullets[i].eraseBullet();
				//bullets.erase(bullets.begin() +i );
			}
			
	
		}
		

	}
	room.CollisionBW(bullets);
	/*for (int i = 0; i < enemies.size(); i++) {
         if (CollisionC(hero, enemies[i]))
				hero.getHit(enemies[i]);
	}*/
	for (int j = 0; j < enemies.size(); j++) {
		if (CollisionC(hero, enemies[j]))
			hero.getHit(enemies[j]);
		enemies[j]->update();
	}
	/*for (int j = 0; j < items.size(); j++) {
		if (CollisionHI(hero, items[j])) {
			hero.getItem(items[j]);
			items[j]->erase();
		}
	}*/
	for (int i = 0; i < items.size();i++) {
		if (CollisionHI(hero, items[i])) {
			hero.getItem(items[i]);
			items[i]->erase();
			//(*it)->erasable();
			//it = items.erase(it);
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

	
	/*
		for (int h = 0; h < enemies.size(); h++)
			if (bullets[j].getX() == enemies[h]->getX() && bullets[j].getY() == enemies[h]->getY())
				enemies.erase(enemies.begin() + h);
	}
	for (int i = 0; i < enemies.size(); i++) {
		enemies[i]->move();
		std::cout << "CordX di " << " " << i << ":" << " " << enemies[i]->getX();
		std::cout << " CordY di " << " " << i << ":" << " " << enemies[i]->getY();
		
	}
	std::cout << room.getHeight();
	std::cout << room.getWidth();*/
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
	
}

void Game::render() {
	SDL_RenderClear(renderer);
	room.drawMap();
	hero.render();
	for (int j = 0; j < enemies.size(); j++)
		enemies[j]->render();
	for (int j = 0; j < bullets.size(); j++)
		bullets[j].render();
	/*for (int j = 0; j < items.size(); j++)
		items[j]->render();*/
	//drawScore(renderer);
	for (int i = 0; i < items.size(); i++)
		items[i]->render();
	SDL_RenderPresent(renderer);
	
}

void Game::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
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

/*bool Game::CollisionWup(Character a, Tile* t) {
	if (a.getRx() >= t->getRx() + t->getRw() && a.getRx() + a.getRw() <= t->getRx() &&
		a.getRy() + a.getRh() <= t->getRy())
		return false;
	else
		return true;
}

bool Game::CollisionWdown(Character a, Tile* t) {
	if (a.getRy() + a.getRh()  >= t->getRy())
		return true;
	else
		return false;
}

bool Game::CollisionWleft(Character a, Tile* t) {
	if (a.getRx() <= t->getRx() + t->getRw())
		return true;
	else
		return false;
}

bool Game::CollisionWright(Character a, Tile* t) {
	if (a.getRx() + a.getRw() <= t->getRx() )
		return true;
	else
		return false;
}*/

/*bool Game::CollisionW(Character a, Tile* t) {
	if(a.getRx() + a.getRw() <t->getRx() || a.getRx() > t->getRx() + t->getRw()  ||
		a.getRy() + a.getRh()  < t->getRy() || a.getRy() > t->getRy() + t->getRh() )
		return false;
	else
		return true;
}

bool Game::under(Character a, Tile* t) {
	if (a.getRy() >= t->getRy() + t->getRh() && (a.getRx() >= t->getRx() || a.getRx()<= t->getRx() + t->getRw()))
		return true;
	else
		return false;
}

bool Game::over(Character a, Tile* t) {
	if (a.getRy() + a.getRh() <= t->getRy())
		return true;
	else
		return false;
}

bool Game::left(Character a, Tile* t) {
	if (a.getRx() + a.getRw() <= t->getRx())
		return true;
	else
		return false;
}

bool Game::right(Character a, Tile* t) {
	if (a.getRx() >= t->getRx() + t->getRw())
		return true;
	else
		return false;
}

/*bool Game::CollisionBW(Bullet a, Tile* t) {
	if (a.getRx() + a.getRw() <t->getRx() || a.getRx() > t->getRx() + t->getRw() ||
		a.getRy() + a.getRh()  < t->getRy() || a.getRy() > t->getRy() + t->getRh())
		return false;
	else
		return true;
}*/

bool Game::CollisionHI(Character a, Item * b)
{
	if (a.getRx() + a.getRw() < b->getRx() || a.getRx() > b->getRx() + b->getRw() ||
		a.getRy() + a.getRh() < b->getRy() || a.getRy() > b->getRy() + b->getRh() )
		return false;
	else
		return true;
}

void Game::drawScore(SDL_Renderer * rend) {
	TTF_Font* Sans = TTF_OpenFont("Sans.ttf", 24); 

	SDL_Color Red = { 255, 255, 255 };

	SDL_Surface* surfaceMessage = TTF_RenderText_Solid(Sans, "punteggio: 3", Red); 

	SDL_Texture* Message = SDL_CreateTextureFromSurface(rend, surfaceMessage); 

	SDL_Rect Message_rect; 
	Message_rect.x = 0;  
	Message_rect.y = 0; 
	Message_rect.w = 100; 
	Message_rect.h = 100; 

	SDL_RenderCopy(rend, Message, NULL, &Message_rect);
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
		strike = true;
	}
	firstStrike = true;
}