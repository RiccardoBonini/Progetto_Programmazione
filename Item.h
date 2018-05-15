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
private:
	float coordX;
	float coordY;
	int dropRate;
	int hpValue;
	int damageValue;
	float speedValue;
		
};

