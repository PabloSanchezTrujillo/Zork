#ifndef WORLD_H
#define WORLD_H

#include<vector>
#include "Entity.h"

class World {
private:
	vector<Entity*> entities;

public:
	World(vector<Entity*>);
	~World();
};

#endif // !WORLD_H