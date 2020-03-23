#ifndef CREATURE_H
#define CREATURE_H

#include "Entity.h"
#include "Room.h"

using namespace std;

class Creature : public Entity {
private:
	Room* location;

public:
	Creature(type, string, string, list<Entity*>, Room*);
	~Creature();
};

#endif // !CREATURE_H
