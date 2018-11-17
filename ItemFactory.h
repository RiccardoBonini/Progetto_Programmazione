#pragma once
#include"Item.h"
class ItemFactory
{
public:
	static Item*createItem(char choice, int x, int y);
};


