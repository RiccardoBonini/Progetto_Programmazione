#pragma once
#include "Enemy.h"

class EnemyFactory
{
public:
	static Enemy* makeEnemy(char choice, int bound1, int bound2);
};

