#pragma once
class Bullet
{
public:
	Bullet(float X, float Y, bool Dir, bool Inc);
	~Bullet();
	void update();
	float getX() { return coordX; };
	float getY() { return coordY; };
	int getDmg() { return damage; };
private:
	float coordX;
	float coordY;
	int damage;
	bool dir;
	bool inc;
	
};

