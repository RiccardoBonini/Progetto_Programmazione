#include "TileFactory.h"

Tile * TileFactory::makeTile(char choice, int x, int y)
{
	if (choice == 'w')
		return new Wall(x, y);
	if (choice == 'g')
		return  new Ground(x, y, false);
	if(choice== 's')
		return  new Ground(x, y, true);
	if (choice == 'p')
		return new Pillar(x, y);
	if (choice == 'b')
		return new Barrel(x, y);

	
}
