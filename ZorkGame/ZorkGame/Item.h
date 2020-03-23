#ifndef ITEM_H
#define ITEM_H

#include "Entity.h"

class Item : Entity {
private:

public:
	Item(type, string, string, list<Entity*>);
	~Item();
};

#endif // !ITEM_H
