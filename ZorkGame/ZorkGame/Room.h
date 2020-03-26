#ifndef ROOM_H
#define ROOM_H

#include<vector>
#include "Entity.h"

class Exit;

using namespace std;

class Room : public Entity {
private:
	bool isPlayerInside;
	vector<Exit*> exits;

public:
	Room(type, string, string, list<Entity>, bool);
	~Room();
	void update();
	void addExit(Exit*);
	vector<Exit*> getExits();
};

#endif // !ROOM_H