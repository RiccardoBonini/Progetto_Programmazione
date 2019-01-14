#include "MovementBehavior.h"

 MovementBehavior::MovementBehavior() {}



 void ZombieBehavior::move(Enemy & enemy, Hero hero)
 {
	 if (enemy.HeroIsSpotted() == true) {

		 if (enemy.getRy()<hero.getRy() && enemy.getDown() == true)
			 enemy.setRy(enemy.getRy() + enemy.getSpd());
		 else if (enemy.getRy()>hero.getRy() && enemy.getUp() == true)
			 enemy.setRy(enemy.getRy() - enemy.getSpd());
		 if (enemy.getRx()<hero.getRx() && enemy.getRight() == true)
			 enemy.setRx(enemy.getRx() + enemy.getSpd());
		 else if (enemy.getRx()>hero.getRx() && enemy.getLeft() == true)
			 enemy.setRx(enemy.getRx() - enemy.getSpd());
	 }
	 else if (enemy.getRight() == true || enemy.getLeft() == true) {
		 if (enemy.getRight() == true && enemy.getLeft() == false)
			 enemy.setDirezione(1);
		 else if (enemy.getRight() == false && enemy.getLeft() == true)
			 enemy.setDirezione(-1);
		 int spd = enemy.getDirezione() * enemy.getSpd();
		 
		 enemy.setRx(enemy.getRx() + spd);

	 }
	 

 }

 void GoblinBehavior::move(Enemy & enemy, Hero hero)
 {
	 if (enemy.HeroIsSpotted() == true) {

		 if (enemy.getRy()<hero.getRy() && enemy.getUp() == true)
			 enemy.setRy(enemy.getRy() - enemy.getSpd());
		 else if (enemy.getRy()>hero.getRy() && enemy.getDown() == true)
			 enemy.setRy(enemy.getRy() + enemy.getSpd());
		 if (enemy.getRx()<hero.getRx() && enemy.getLeft() == true)
			 enemy.setRx(enemy.getRx() - enemy.getSpd());
		 else if (enemy.getRx()>hero.getRx() && enemy.getRight() == true)
			 enemy.setRx(enemy.getRx() + enemy.getSpd());
	 }
	 else {
		 int i = rand() % 2;
		 int j = rand() % 2;
		 if(i==1 && enemy.getRight()==true)
			 enemy.setRx(enemy.getRx() + enemy.getSpd());
		 else if(i==2 && enemy.getLeft()==true)
			 enemy.setRx(enemy.getRx() - enemy.getSpd());
		 if(j==1 && enemy.getUp()==true)
			 enemy.setRy(enemy.getRy() - enemy.getSpd());
		 else if(j==2 && enemy.getDown()==true)
			 enemy.setRy(enemy.getRy() + enemy.getSpd());
	 }
	 
 }

 void WerewolfBehavior::move(Enemy & enemy, Hero hero)
 {
	 if (enemy.HeroIsSpotted()==true) {
		 
		 if(enemy.getRy()<hero.getRy() && enemy.getDown()==true)
			 enemy.setRy(enemy.getRy() + enemy.getSpd());
		 else if(enemy.getRy()>hero.getRy() && enemy.getUp()==true)
			 enemy.setRy(enemy.getRy() - enemy.getSpd());
		 if(enemy.getRx()<hero.getRx() && enemy.getRight()==true)
			 enemy.setRx(enemy.getRx() + enemy.getSpd());
		 else if(enemy.getRx()>hero.getRx() && enemy.getLeft()==true)
			 enemy.setRx(enemy.getRx() - enemy.getSpd());
	 }
	 else if (enemy.getDown() == true || enemy.getUp() == true) {
		 if (enemy.getDown() == true && enemy.getUp() == false)
			 enemy.setDirezione(1);
		 if (enemy.getDown() == false && enemy.getUp() == true)
			 enemy.setDirezione(-1);
		 int spd = enemy.getDirezione() * enemy.getSpd();
		 enemy.setRy(enemy.getRy() + spd);

		 
	 }
	
 }
