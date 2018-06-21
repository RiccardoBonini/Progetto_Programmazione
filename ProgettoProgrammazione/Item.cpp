#include "Item.h"



Item::Item(){
}

Item::~Item()
{
}

Item * Item::createItem(char choice){
	if (choice == 'p')
		return new Potion;
	if (choice == 'a')
		return new Ak47;
	if (choice == 's')
		return new MightySpoon;
}

Potion::Potion() {
	hpValue = 50;
	damageValue = 0;
	speedValue = 0;
}

Ak47::Ak47() {
	hpValue = 0;
	damageValue = 25;
	speedValue = 0;
}

MightySpoon::MightySpoon() {
	hpValue = 250;
	damageValue = 150;
	speedValue = 5;
}

