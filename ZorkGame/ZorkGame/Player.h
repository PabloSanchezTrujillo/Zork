#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include<list>

class Player : public Creature {
private:
	list<Item*> inventory;
	string action;
	bool isOutside;

public:
	Player();
	Player(type, string, string, list<Item*>, Room*);
	~Player();
	void update();
	void CheckExit();
	bool isPlayerOutside();
};

#endif // !PLAYER_H
