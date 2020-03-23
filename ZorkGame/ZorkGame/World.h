#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include "Entity.h"

using namespace std;

class World {
private:
	vector<Entity*> entities;

public:
	World();
	World(vector<Entity*>);
	~World();
	Entity* getEntity(int);
};

#endif // !WORLD_H