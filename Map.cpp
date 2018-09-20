//#include "Game.h"
#include"Map.h"
#include"TileFactory.h"

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
				id++;
				ntile++;
			}
			//tiles.push_back(TileFactory::makeTile('w', x, y));
		//tiles.push_back(EnemyFactory::makeEnemy('g', x, y));
//SDL_RenderCopy(Game::renderer, wall, NULL, &dest);
//TextureManager::draw(wall, src, dest);
			else if (muro == 0) {
				//tiles[id] = TileFactory::makeTile('g', x, y);
				tiles.push_back(TileFactory::makeTile('g', x, y));
				id++;
				ntile++;
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
