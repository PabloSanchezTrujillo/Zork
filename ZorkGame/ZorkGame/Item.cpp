#include "Item.h"

Item::Item(type _entityType, string _name, string _description, list<Entity*> _contains) : Entity(_entityType, _name, _description, _contains) {
}

Item::~Item()
{
}