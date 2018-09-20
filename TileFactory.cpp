#include "TileFactory.h"

Tile * TileFactory::makeTile(char choice, int x, int y)
{
	if (choice == 'w')
		return new Wall(x, y);
	if (choice == 'g')
		return  new Ground(x, y);
	
}
