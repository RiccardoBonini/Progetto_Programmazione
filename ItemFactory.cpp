#include "ItemFactory.h"

Item * ItemFactory::createItem(char choice, int x, int y)
{
	if (choice == 'p')
		return new Potion(x,y);
	if (choice == 'b')
		return new Bazooka(x,y);
	if (choice == 'f')
		return new MightyFork(x,y);
}
