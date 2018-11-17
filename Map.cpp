//#include "Game.h"
#include"Map.h"
#include"TileFactory.h"
#include "Bullet.h"

int lvl[20][50] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, }
	};

Map::Map()
{
	width = 50;
	height = 10;
	ntile = 0;
	/*wall = Game::LoadTexture("sprite/wall2.png");
	terrain = Game::LoadTexture("sprite/terrain.png");
	src.x = src.y = dest.x = dest.y = 0;
	src.h = src.w = dest.h = dest.w = 32;*/

	/*for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++)
			map[i][j] = lvl[i][j];
	}*/
	//int muro = 0;
	/*for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			//muro = map[i][j];
			int x = j * 32;
			int y = i * 32;
			if (lvl[i][j] == 1)
				tiles.push_back(TileFactory::makeTile('w', x, y));
			//SDL_RenderCopy(Game::renderer, wall, NULL, &dest);
			//TextureManager::draw(wall, src, dest);
			else if (lvl[i][j] == 0)
				tiles.push_back(TileFactory::makeTile('g', x, y));
			//SDL_RenderCopy(Game::renderer, terrain, NULL, &dest);
			//TextureManager::draw(terrain, src, dest);
			else
				break;
		}
	}*/

}

void Map::loadMap() {
	int muro = 0;
	int id = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			muro = lvl[i][j];
	        int x = j * 32;
	        int y = i * 32;
			if (muro == 1) {
				//tiles[id] = TileFactory::makeTile('w', x, y);
				tiles.push_back(TileFactory::makeTile('w', x, y));
				
				
			}
			//tiles.push_back(TileFactory::makeTile('w', x, y));
		//tiles.push_back(EnemyFactory::makeEnemy('g', x, y));
//SDL_RenderCopy(Game::renderer, wall, NULL, &dest);
//TextureManager::draw(wall, src, dest);
			else if (muro == 0) {
				//tiles[id] = TileFactory::makeTile('g', x, y);
				tiles.push_back(TileFactory::makeTile('g', x, y));
				
			}
			//tiles.push_back(TileFactory::makeTile('g', x, y));
		//tiles.push_back(EnemyFactory::makeEnemy('w', x, y));
//SDL_RenderCopy(Game::renderer, terrain, NULL, &dest);
//TextureManager::draw(terrain, src, dest);
			
		}
	}


}

Map::~Map()
{
}

void Map::drawMap() {
	/*int muro = 0;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 50; j++) {
			muro = map[i][j];
			dest.x = j * 32;
			dest.y = i * 32;
			if (muro == 1)
				//tiles.push_back(TileFactory::makeTile('w', x, y));
			SDL_RenderCopy(Game::renderer, wall, NULL, &dest);
			//TextureManager::draw(wall, src, dest);
			else if (muro == 0)
				//tiles.push_back(TileFactory::makeTile('g', x, y));
			SDL_RenderCopy(Game::renderer, terrain, NULL, &dest);
			//TextureManager::draw(terrain, src, dest);
		}
	}*/
	/*for (int i = 0; i < ntile; i++) {
		tiles[i]->render();
		
	}*/
	for (int i = 0; i < tiles.size(); i++)
		tiles[i]->render();
	
}

void Map::update() {
	for (int i = 0; i < ntile; i++) {
		tiles[i]->update();

	}
}

void Map::CollisionBW(std::vector<Bullet> &bullets)
{
	/*for (int i = 0; i < tiles.size(); i++) {
		
		if (a.getRx() + a.getRw() < tiles[i]->getRx() || a.getRx() > tiles[i]->getRx() + tiles[i]->getRw() ||
			a.getRy() + a.getRh() < tiles[i]->getRy() || a.getRy() > tiles[i]->getRy() + tiles[i]->getRh())
			return false;
		else if (tiles[i]->solid() == true)
			return true;
		/*if (a.getRx() + a.getRw() > tiles[i]->getRx() && a.getRx() < tiles[i]->getRx() + tiles[i]->getRw() &&
			a.getRy() + a.getRh() > tiles[i]->getRy() && a.getRy() < tiles[i]->getRy() + tiles[i]->getRh() && tiles[i]->solid() == true)
			return true;
		else
			return false;

	
	
	}*/
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			for (int j = 0; j < bullets.size(); j++) {
				{
					if (bullets[j].getRx() + bullets[j].getRw() < tiles[i]->getRx() || bullets[j].getRx() > tiles[i]->getRx() + tiles[i]->getRw() ||
						bullets[j].getRy() + bullets[j].getRh() < tiles[i]->getRy() || bullets[j].getRy() > tiles[i]->getRy() + tiles[i]->getRh())
						;
					else
						bullets[j].eraseBullet();

				}
			}
		}
	}
	
}

bool Map::CollisionCW(int x, int y, int w, int h)
{
	bool pos = false;
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			if (x + w  < tiles[i]->getRx() || x > tiles[i]->getRx() + tiles[i]->getRw()
				|| y + h < tiles[i]->getRy() + tiles[i]->getRh() || y > tiles[i]->getRy() + tiles[i]->getRh())
				pos = false;
			else {
				return true;
			}
		}
	}
	return pos;
}

bool Map::CollisionCWup(int x, int y, int w, int h, int speed)
{
	int newY = y - speed;
	bool pos = false;
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			if (x + w  < tiles[i]->getRx() || x > tiles[i]->getRx() + tiles[i]->getRw()
				|| newY + h < tiles[i]->getRy() ||newY > tiles[i]->getRy() + tiles[i]->getRh())
				pos = false;
			else {
				target = tiles[i];
				return true;
			}
		}
	}
	return pos;
}

bool Map::CollisionCWdown(int x, int y, int w, int h, int speed)
{
	int newY = y + speed;
	bool pos = false;
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			if (x + w  < tiles[i]->getRx() || x > tiles[i]->getRx() + tiles[i]->getRw()
				|| newY+ h < tiles[i]->getRy() || newY > tiles[i]->getRy() + tiles[i]->getRh())
				pos = false;
			else {
				target = tiles[i];
				return true;
			}
		}
	}
	return pos;
}

bool Map::CollisionCWleft(int x, int y, int w, int h, int speed)
{
	int newX = x - speed ;
	bool pos = false;
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			if (newX + w  < tiles[i]->getRx() || newX > tiles[i]->getRx() + tiles[i]->getRw()
				|| y + h < tiles[i]->getRy() || y > tiles[i]->getRy() + tiles[i]->getRh())
				pos = false;
			else {
				target = tiles[i];
				return true;
			}
		}
	}
	return pos;
}

bool Map::CollisionCWright(int x, int y, int w, int h, int speed)
{
	int newX = x + speed ;
	bool pos = false;
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			if (newX + w  < tiles[i]->getRx() || newX > tiles[i]->getRx() + tiles[i]->getRw()
				|| y + h < tiles[i]->getRy() || y > tiles[i]->getRy() + tiles[i]->getRh())
				pos = false;
			else {
				target = tiles[i];
				return true;
			}
		}
	}
	return pos;
}

void Map::setUp(Character & hero)
{
	hero.setRy(target->getRy() + target->getRh() +1);
}

void Map::setDown(Character & hero)
{
	hero.setRy(target->getRy() -hero.getRh() -1);
}

void Map::setLeft(Character & hero)
{
	hero.setRx(target->getRx() + target->getRw() + 1);
}

void Map::setRight(Character & hero)
{
	hero.setRx(target->getRx() - hero.getRw() - 1);
}
