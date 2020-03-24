#include "Room.h"

Room::Room(type _entityType, string _name, string _description, list<Entity*> _contains, bool _isPlayerInside)
	: Entity(_entityType, _name, _description, _contains) {
	isPlayerInside = _isPlayerInside;
}

Room::~Room()
{
}

void Room::update() {
	if(isPlayerInside) {
		//cout << "You are in the " << getName() << ". " << getDescription() << endl;
		//cout << "\n";
	}
}

void Room::addExit(Exit* exit) {
	exits.push_back(exit);
}

vector<Exit*> Room::getExits() {
	return exits;
}