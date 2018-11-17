#include "Observer.h"



void ScoreObserver::update()
{
	int score = getTarget()->getDeadEnemies();
	if (score >= 2)
		getTarget()->deadStrike();
}



