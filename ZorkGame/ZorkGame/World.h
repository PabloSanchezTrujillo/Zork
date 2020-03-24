#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include "Entity.h"
#include "Exit.h"
#include "Player.h"

using namespace std;

class World {
private:
	vector<Entity*> entities;
	vector<Room*> houseRooms;
	vector<Exit*> houseConnections;
	vector<Item*> houseItems;
	Player* player;

public:
	World();
	World(vector<Entity*>);
	~World();
	void createItems();
	void CreateRooms();
	void ConnectRooms();
	Room* getRoom(string);
	Item* getItem(string);
	vector<Entity*> getEntities();
	Player* getPlayer();
};

#endif // !WORLD_H