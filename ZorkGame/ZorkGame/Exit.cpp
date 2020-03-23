#include "Exit.h"

Exit::Exit(type _entityType, string _name, string _description, direction _exitDirection, Room* _source, Room* _destination) : Entity(_entityType, _name, _description) {
	exitDirection = _exitDirection;
	source = _source;
	destination = _destination;
}

Exit::~Exit() {
}