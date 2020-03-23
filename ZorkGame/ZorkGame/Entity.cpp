#include "Entity.h"

Entity::Entity(type _entityType, string _name, string _description, list<Entity*> _contains) {
	entityType = _entityType;
	name = _name;
	description = _description;
	contains = _contains;
}

void Entity::update()
{
}