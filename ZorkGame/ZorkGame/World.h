#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include "Entity.h"
#include "Exit.h"

using namespace std;

class World {
private:
	vector<Entity*> entities;
	vector<Room*> houseRooms;
	vector<Exit*> houseConnections;

public:
	World();
	World(vector<Entity*>);
	~World();
	void CreateRooms();
	void ConnectRooms();
	Room* getRoom(int);
	Room* findRoom(string);
};

#endif // !WORLD_H