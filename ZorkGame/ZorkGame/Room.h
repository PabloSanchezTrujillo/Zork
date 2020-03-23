#ifndef ROOM_H
#define ROOM_H

#include "Entity.h"

using namespace std;

class Room : public Entity {
public:
	Room(type, string, string);
	Room(type, string, string, list<Entity*>);
	~Room();
};

#endif // !ROOM_H