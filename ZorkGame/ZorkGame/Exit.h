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
	bool isLocked;
	Entity itemToUnlock;

public:
	Exit(type, string, string, direction, Room*, Room*, bool);
	Exit(type, string, string, direction, Room*, Room*, bool, Entity);
	~Exit();
	string directionToString();
	Room* getDestination();
	bool isRoomLocked();
	bool unlock(Entity);
};

#endif // !EXIT_H
