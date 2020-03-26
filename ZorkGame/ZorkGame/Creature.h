#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h"
#include "Item.h"

using namespace std;

class Creature : public Entity {
protected:
	Room* location;

public:
	Creature();
	Creature(type, string, string, list<Entity>, Room*);
	Creature(type, string, string, Room*);
	~Creature();
	Room* getLocation();
};

#endif // !CREATURE_H
