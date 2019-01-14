#include "Observer.h"



void ScoreObserver::update()
{
	int score = getTarget()->getDeadEnemies();
	if (score >= 4) 
		getTarget()->massacre();
	else if (score >= 2)
		getTarget()->deadStrike();
}

void SurroundingObserver::update()
{
	int score = getTarget()->getBrokenThings();
	if (score >= 4)
		getTarget()->vandal();
	
}
