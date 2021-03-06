#include "pch.h"



#include"../ProgettoProgrammazione/Hero.cpp"

#include"../ProgettoProgrammazione/Character.cpp"*/

#include"../ProgettoProgrammazione/Game.cpp"

#include"../ProgettoProgrammazione/Enemy.cpp"

#include"../ProgettoProgrammazione/Bullet.cpp"

#include"../ProgettoProgrammazione/Item.cpp"

#include"../ProgettoProgrammazione/ItemFactory.cpp"

#include"../ProgettoProgrammazione/Map.cpp"

#include"../ProgettoProgrammazione/MovementBehavior.cpp"

#include"../ProgettoProgrammazione/Observer.cpp"

#include"../ProgettoProgrammazione/Text.cpp"

#include"../ProgettoProgrammazione/Tile.cpp"

#include"../ProgettoProgrammazione/TileFactory.cpp"

#include"../ProgettoProgrammazione/EnemyFactory.cpp"

TEST(CharacterTest, Values) {

	Hero h =  Hero(0, 0);
	Goblin g = Goblin(0, 0);
	Zombie z = Zombie(0, 0);
	Werewolf w = Werewolf(0, 0);

  EXPECT_EQ(h.getHp(), 250);
  EXPECT_EQ(h.getDmg(), 30);
  EXPECT_EQ(h.getSpd(), 15);

  EXPECT_EQ(g.getHp(), 50);
  EXPECT_EQ(g.getDmg(), 500);
  EXPECT_EQ(g.getSpd(), 2);

  EXPECT_EQ(z.getHp(), 100);
  EXPECT_EQ(z.getDmg(), 2);
  EXPECT_EQ(z.getSpd(), 1);

  EXPECT_EQ(w.getHp(), 150);
  EXPECT_EQ(w.getDmg(), 5);
  EXPECT_EQ(w.getSpd(), 2);


}

TEST(HeroTest, HeroMovement) {
	
	Hero h = Hero(0, 50);	                                                                //mandiamo l'eroe contro un muro di tile solidi a destra
	std::vector<Tile *> wall;                                                               //deve essere verificata la collisione 
	bool rightCollision = false;
	Tile * target;
	for(int i= 0; i< 20; i++)
		wall.push_back(TileFactory::makeTile('w', 250, i*32));
	for (int i = 0; i < 1000; i++) {                                                         
		for (int j = 0; j < wall.size(); j++) {
			if (Map::CollisionCW(h.getRx() + h.getSpd(), h.getRy(), h.getRh(), h.getRw(), wall[j]) == true) {    //viene verificato ad ogni ciclo se l'eroe 
				rightCollision = true;                                                                           //sta per collidere con qualcosa a destra
				target = wall[j];                                                                                //se ci� non avviene, l'eroe pu� muoversi verso destra,   
			}                                                                                                    //altrimenti verra posto 1 pixel a sinistra del tile target,
		}                                                                                                        //che indica il tile col quale si sta per scontrare
		if (rightCollision == false)                                                                             //in questo modo se l'eroe si trova ad una distanza pi� piccola della sua velocit�
			h.move(true, true);                                                                                  //da un tile solido, coprir� la distanza rimanente
		else
			h.setRx(target->getRx() - h.getRw() - 1);
	}

	EXPECT_TRUE(h.getRx() + h.getRw() < 250);                                               //l'eroe non deve essere andato oltre il muro
}

TEST(HeroTest, Shooting) {

	Hero h = Hero(0, 0);
	Enemy *e = EnemyFactory::makeEnemy('z', 5, 0);                         //creiamo uno zombie ad una determintata distanza da hero, 
	std::vector<Bullet> bullets;                                            //facciamo sparare 5 colpi, sufficienti per ucciderlo, verso il nemico 
	for(int j=0; j<50; j++) {                                                //alla fine del ciclo il nemico deve essere morto
		bullets.push_back(Bullet(h.getRx(), h.getRy(), true, true)); 
		for (int i = 0; i < bullets.size(); i++) {
			bullets[i].update();
			if (Game::CollisionB(e, bullets[i]))
				e->getShot(bullets[i]);
		}
		//e->update(h);
	
	}
	EXPECT_TRUE(!(e->isAlive()));
}

TEST(HeroTest, ItemPicking) {
	Hero h = Hero(50, 0);
	std::vector<Item *> items; 
	items.push_back(ItemFactory::createItem('f', 150, 0));                  //mettiamo 3 oggetti diversi in gioco. L'eroe li raccatta tutti e 3 
	items.push_back(ItemFactory::createItem('p', 180, 0));                  //e devono venire modificati i suoi valori di hp, speed e damage
	items.push_back(ItemFactory::createItem('b', 210, 0));                  //una volta raccattati gli oggetti devono essere eliminati correttamente 
	while (h.getRx() < 220) {                                               //dal vettore che li contiene
		h.move(true, true);
		for (int i = 0; i < items.size(); i++) {
			if (Game::CollisionHI(h, items[i])) {
				h.getItem(items[i]);
				items[i]->erase();
			}
		}
		for (int i = 0; i < items.size(); i++) {
			if (items[i]->isErasable())
				items.erase(items.begin() + i);
		}

	}

	
	EXPECT_EQ(h.getHp(), 550);
	EXPECT_EQ(h.getDmg(), 205);                                            //verifica della corretta modifica degli attributi
	EXPECT_EQ(h.getSpd(), 20);

	EXPECT_EQ(items.size(), 0);                                            //verifica che gli oggetti siano stati rimossi dal vettore
}       

TEST(EnemyTest, Death) {

	std::vector<Enemy*> enemies;
	int enemiesNum = 30000;
	Bullet b = Bullet(0, 0, true, true);                                                   //proiettile ed eroe fittizi
	for (int i = 0; i < enemiesNum; i++) {
		enemies.push_back(EnemyFactory::makeEnemy('g', rand() % 100, rand() % 100));       //creiamo 30 nemici che vengono colpiti da un proiettile
	}                                                                                      //quando sono morti tutti verifichiamo che vengano correttamente
	while (enemiesNum > 0) {                                                               //rimossi dal vettore che li contiene
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->getShot(b);
			if (enemies[i]->isAlive() == false) {
				enemies[i]->erase();
			}
			
		}
		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i]->isErasable()) {
				enemies.erase(enemies.begin() + i);
				enemiesNum--;
			}
		}
	}

	EXPECT_EQ(enemies.size(), 0);
} 

TEST(EnemyTest, AttackHero) {

	Hero h = Hero(10, 10);
	std::vector<Enemy*> enemies;
	int time = 1000;
	for (int i = 0; i < 50; i++) {
		enemies.push_back(EnemyFactory::makeEnemy('g', rand() % 20, rand() % 20));     //creiamo 50 lupi mannari vicino all'eroe
	}
	while (time > 1) {
		for (int i = 0; i < enemies.size(); i++) {
			enemies[i]->update(h);                                                    //grazie al loro behavior, i nemici attaccheranno
			enemies[i]->move(h);                                                      //l'eroe se in sua prossimit�
			if (Game::CollisionC(h, enemies[i]))                                      //quando scade il tempo l'eroe deve essere morto
				h.getHit(enemies[i]);
		}
		h.update();
		time--;
	}

	EXPECT_TRUE(h.getHp() <= 0);
}

int main(int argc, char **argv) {
	testing::InitGoogleTest(&argc, argv);
	
	RUN_ALL_TESTS();
	system("pause");
	

	
		
}