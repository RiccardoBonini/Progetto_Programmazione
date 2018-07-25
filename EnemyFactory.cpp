#include "EnemyFactory.h"



Enemy* EnemyFactory::makeEnemy(char choice, int bound1, int bound2) {
	if (choice == 'g')
		return new Goblin(bound1, bound2);
	if (choice == 'z')
		return  new Zombie(bound1, bound2);
	if (choice == 'w')
		return  new Werewolf(bound1, bound2);
}

