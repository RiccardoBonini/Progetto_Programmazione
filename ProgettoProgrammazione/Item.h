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

protected:
	float coordX;
	float coordY;
	int dropRate;
	int hpValue;
	int damageValue;
	float speedValue;
		
};

class Potion :public Item {
public:
	Potion();
};

class Ak47 :public Item {
public:
	Ak47();
};

class MightySpoon : public Item {
public:
	MightySpoon();
};

