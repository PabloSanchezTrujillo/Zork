#include "Entity.h"

Entity::Entity() {
}

Entity::Entity(type _entityType, string _name, string _description, list<Entity> _contains) {
	entityType = _entityType;
	name = _name;
	description = _description;
	contains = _contains;
}

Entity::Entity(type _entityType, string _name, string _description) {
	entityType = _entityType;
	name = _name;
	description = _description;
}

Entity::~Entity() {
}

void Entity::update()
{
}

string Entity::getName() {
	return name;
}

string Entity::getDescription() {
	return description;
}

list<Entity> Entity::getItems() {
	return contains;
}

void Entity::popFront() {
	contains.pop_front();
}

void Entity::pushBack(Entity entity) {
	contains.push_back(entity);
}