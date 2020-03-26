#include "Exit.h"
#include "Room.h"

Exit::Exit(type _entityType, string _name, string _description, direction _exitDirection, Room* _source, Room* _destination, bool _isLocked)
	: Entity(_entityType, _name, _description) {
	exitDirection = _exitDirection;
	source = _source;
	destination = _destination;
	isLocked = _isLocked;

	source->addExit(this);
}

Exit::Exit(type _entityType, string _name, string _description, direction _exitDirection, Room* _source, Room* _destination, bool _isLocked, Entity _itemToUnlock)
	: Entity(_entityType, _name, _description) {
	exitDirection = _exitDirection;
	source = _source;
	destination = _destination;
	isLocked = _isLocked;
	if(isLocked) {
		itemToUnlock = _itemToUnlock;
	}

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

bool Exit::isRoomLocked()
{
	return isLocked;
}

bool Exit::unlock(Entity itemUsed) {
	if(isLocked) {
		if(itemToUnlock.getName() == itemUsed.getName()) {
			isLocked = false;
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return true;
	}
}