#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"
#include "Room.h"

using namespace std;

class Exit : Entity {
public:
	enum direction {
		north,
		south,
		east,
		west,
		up,
		down
	};

private:
	direction exitDirection;
	Room* source;
	Room* destination;

public:
	Exit(type, string, string, list<Entity*>, direction, Room*, Room*);
};

#endif // !EXIT_H
