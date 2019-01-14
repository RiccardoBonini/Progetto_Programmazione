
#include"Map.h"
#include"TileFactory.h"
#include "Bullet.h"
#include "EnemyFactory.h"

int lvl[23][50] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1, },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,3,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,5,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,4,0,0,0,0,0,0,0,0,0,5,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,3,0,0,0,0,0,0,0,0,5,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,0,0,0,3,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,0,0,0,0,5,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,4,0,0,0,0,0,0,0,4,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,4,4,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,5,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,3,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,5,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1, },
	    { 1,1,1,1,1,1,3,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,1,1,1,0,3,0,0,1,1,1,1,1,1,1, },
        { 2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2, },
        { 2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,0,0,0,0,1,2,2,2,2,2,2, },
        { 2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,1,1,1,1,1,2,2,2,2,2,2, },
        /*{ 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, },
        { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2, },*/
       
	};

Map::Map()
{
	width = 50;
	height = 10;
	ntile = 0;
	

}

void Map::loadMap() {
	int muro = 0;
	int id = 0;
	for (int i = 0; i < 23; i++) {
		for (int j = 0; j < 50; j++) {
			muro = lvl[i][j];
	        int x = j * 32;
	        int y = i * 32;
			if (muro == 1) {
				
				tiles.push_back(TileFactory::makeTile('w', x, y));
				
				
			}
			
			else if (muro == 0) {
				
				tiles.push_back(TileFactory::makeTile('g', x, y));
				
			}
			else if (muro == 3) {
				tiles.push_back(TileFactory::makeTile('s', x, y));
			}
			else if (muro == 4) {
				tiles.push_back(TileFactory::makeTile('g', x, y));
				tiles.push_back(TileFactory::makeTile('p', x, y));
			}
			else if (muro == 5) {
				tiles.push_back(TileFactory::makeTile('g', x, y));
				tiles.push_back(TileFactory::makeTile('b', x, y));
			}
			
			
		}
	}


}

Map::~Map()
{
}

void Map::drawMap() {
	
	for (int i = 0; i < tiles.size(); i++)
		tiles[i]->render();
	
}

void Map::update() {
	for (int i = 0; i < ntile; i++) {
		tiles[i]->update();

	}
}

void Map::CollisionBW(std::vector<Bullet> &bullets, int &brokenThings)
{
	
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			for (int j = 0; j < bullets.size(); j++) {
				{
					if (bullets[j].getRx() + bullets[j].getRw() < tiles[i]->getRx() || bullets[j].getRx() > tiles[i]->getRx() + tiles[i]->getRw() ||
						bullets[j].getRy() + bullets[j].getRh() < tiles[i]->getRy() || bullets[j].getRy() > tiles[i]->getRy() + tiles[i]->getRh())
						;
						
					else {
						if (tiles[i]->isBreakable()){
							tiles[i]->erase(); 
						brokenThings++;
						}
						
						bullets[j].eraseBullet();
					}

				}
			}
		}
	}
	
}

bool Map::CollisionCW(int x, int y, int w, int h, Tile * t)
{
	if (t->solid()) {
		if (x + w  < t->getRx() || x > t->getRx() + t->getRw()
			|| y + h < t->getRy() + t->getRh() || y > t->getRy() + t->getRh())
			return false;
		else
			return true;

	}
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

void Map::spawnEnemies(std::vector<Enemy*> &enemies,int enemiesNum)
{
	int i = 0;
	while (enemiesNum > 0) {
		if (tiles[i % tiles.size()]->spawnPoint() == true) {
			enemiesNum--;
			int k = rand() % 3;
			if(k==0)
				enemies.push_back(EnemyFactory::makeEnemy('g',tiles[i % tiles.size()]->getRx() ,tiles[i % tiles.size()]->getRy() ));
			else if(k==1)
				enemies.push_back(EnemyFactory::makeEnemy('z', tiles[i % tiles.size()]->getRx(), tiles[i % tiles.size()]->getRy()));
			else if(k==2)
				enemies.push_back(EnemyFactory::makeEnemy('w', tiles[i % tiles.size()]->getRx(), tiles[i % tiles.size()]->getRy()));
			
		}
		i++;
	}
}

void Map::erase()
{
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->isErasable())
			tiles.erase(tiles.begin() + i);
	}
}

bool Map::CollisionEnemy(int x, int y, int w, int h) {

	bool pos = false;
	for (int i = 0; i < tiles.size(); i++) {
		if (tiles[i]->solid()) {
			if (x + w  < tiles[i]->getRx() || x > tiles[i]->getRx() + tiles[i]->getRw()
				|| y + h < tiles[i]->getRy() || y > tiles[i]->getRy() + tiles[i]->getRh())
				pos = false;
			else {
				
				return true;
			}
		}
	}
	return pos;

}

void Map::adjustX(int speed) {
	for (int i = 0; i < tiles.size(); i++)
		tiles[i]->setRx(tiles[i]->getRx() + speed);
}

void Map::adjustY(int speed) {
	for (int i = 0; i < tiles.size(); i++)
		tiles[i]->setRy(tiles[i]->getRy() + speed);
}


