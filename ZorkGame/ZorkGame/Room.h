#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

using namespace std;

class Room : Entity {
public:
	Room(type, string, string, list<Entity*>);
};

#endif // !ROOM_H