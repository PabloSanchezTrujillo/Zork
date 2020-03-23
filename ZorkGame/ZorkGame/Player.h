#ifndef PLAYER_H
#define PLAYER_H

#include "Creature.h"

class Player : Creature {
private:

public:
	Player(type, string, string, list<Entity*>, Room*);
	~Player();
};

#endif // !PLAYER_H
