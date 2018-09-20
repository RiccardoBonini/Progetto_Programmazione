#pragma once
#include"Tile.h"

class TileFactory
{
public:
	static Tile* makeTile(char choice, int x, int y);
};

