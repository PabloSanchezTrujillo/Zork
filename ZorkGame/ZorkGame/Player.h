#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include<list>

class Player : public Creature {
public:
	enum playerActions {
		search,
		drop,
		use
	};

private:
	list<Item*> inventory;
	string action;
	playerActions playerAction;
	bool isOutside;

public:
	Player();
	Player(type, string, string, list<Item*>, Room*);
	~Player();
	void update();
	bool doAction();
	bool checkExit();
	bool isPlayerOutside();
	bool actionToPlayerAction();
};

#endif // !PLAYER_H
