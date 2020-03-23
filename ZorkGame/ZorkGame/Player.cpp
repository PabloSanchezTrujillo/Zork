#include "Player.h"

Player::Player(type _entityType, string _name, string _description, list<Entity*> _contains, Room* _location)
	: Creature(_entityType, _name, _description, _contains, _location) {
}

Player::~Player()
{
}