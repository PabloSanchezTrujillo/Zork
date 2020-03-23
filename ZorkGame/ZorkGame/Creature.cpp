#include "Creature.h"

Creature::Creature(type _entityType, string _name, string _description, list<Entity*> _contains, Room* _location) : Entity(_entityType, _name, _description, _contains) {
	location = _location;
}

Creature::~Creature()
{
}