#ifndef EXIT_H
#define EXIT_H

#include "Entity.h"

class Room;

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
	Exit(type, string, string, direction, Room*, Room*);
	~Exit();
	string directionToString();
	Room* getDestination();
};

#endif // !EXIT_H
