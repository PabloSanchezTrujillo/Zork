#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"
#include "Item.h"
#include "Exit.h"
#include<list>

using namespace std;

class Player : public Creature {
public:
	enum playerActions {
		search,
		drop,
		use
	};

private:
	list<Entity> inventory;
	string action;
	playerActions playerAction;
	bool isOutside;

public:
	Player();
	Player(type, string, string, list<Entity>, Room*);
	Player(type, string, string, Room*);
	~Player();
	void update();
	bool checkExit();
	bool isPlayerOutside();
	bool actionToPlayerAction();
	void searchRoom();
	void dropItem();
	void dropTheItem(string);
	void useItem();
	void showInventory();
};

#endif // !PLAYER_H
