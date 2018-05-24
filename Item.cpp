#include "Item.h"



Item::Item()
{
	coordX = 0;
	coordY = 0;

	hpValue = 30;
	damageValue = 5;
	speedValue = 3;
}


Item::~Item()
{
}
Item * Item::createItem(char choice){
	if (choice == 'p')
		return new Potion;
	if (choice == 'a')
		return new Ak47;
	if (choice == 's')
		return new spoon;
}

