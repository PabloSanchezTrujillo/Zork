#include "Exit.h"
#include "Room.h"

Exit::Exit(type _entityType, string _name, string _description, direction _exitDirection, Room* _source, Room* _destination) : Entity(_entityType, _name, _description) {
	exitDirection = _exitDirection;
	source = _source;
	destination = _destination;

	source->addExit(this);
}

Exit::~Exit() {
}

string Exit::directionToString() {
	switch(exitDirection) {
	case direction::down:
		return "down";

	case direction::up:
		return "up";

	case direction::north:
		return "north";

	case direction::south:
		return "south";

	case direction::east:
		return "east";

	case direction::west:
		return "west";

	default:
		return "Invalid direction";
	}
}

Room* Exit::getDestination() {
	return destination;
}