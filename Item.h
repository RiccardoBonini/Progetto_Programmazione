#pragma once
class Item
{
public:
	Item();
	~Item();
	float getX() { return coordX; }
	float getY() { return coordY; }
	int getHp() { return hpValue; }
	int getDmg() { return damageValue; }
	float getSpd() { return speedValue; }
	static Item*createItem(char choice);

private:
	float coordX;
	float coordY;
	int dropRate;
	int hpValue;
	int damageValue;
	float speedValue;
		
};
class Potion :public Item {
public:
};
class Ak47 :public Item {
public:
};
class spoon : public Item {
public:
};

