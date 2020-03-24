#include "Player.h"

Player::Player() {
	isOutside = false;
}

Player::Player(type _entityType, string _name, string _description, list<Item*> _inventory, Room* _location)
	: Creature(_entityType, _name, _description, _location) {
	inventory = _inventory;
	isOutside = false;
}

Player::~Player()
{
}

void Player::update() {
	cout << ">";
	cin >> action;
	cout << "\n";
	cout << "Player action: " << action << endl;
	cout << "\n";

	if(actionToPlayerAction()) {
		//switch(playerAction);
	}
	else {
		checkExit();
	}
}

bool Player::doAction() {
}

bool Player::checkExit() {
	for(Exit* exit : location->getExits()) {
		if(action == exit->directionToString()) {
			location = exit->getDestination();
			cout << "You are now in: " << location->getName() << ". " << location->getDescription() << endl;
			cout << "\n";
			return true;
		}
	}

	cout << "That's not a valid action!" << endl;
	cout << "\n";
	return false;
}

bool Player::actionToPlayerAction() {
	if(action == "search") {
		playerAction = playerActions::search;
		return true;
	}
	else if(action == "drop") {
		playerAction = playerActions::drop;
		return true;
	}
	else if(action == "use") {
		playerAction = playerActions::use;
		return true;
	}
	else {
		return false;
	}
}

bool Player::isPlayerOutside() {
	return isOutside;
}