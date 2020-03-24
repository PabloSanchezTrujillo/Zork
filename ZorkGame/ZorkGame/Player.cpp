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

	CheckExit();
}

void Player::CheckExit() {
	for(Exit* exit : location->getExits()) {
		if(action == exit->directionToString()) {
			location = exit->getDestination();
			cout << "You are now in: " << location->getName() << ". " << location->getDescription() << endl;
			cout << "\n";
			return;
		}
	}

	cout << "That's not a valid way!" << endl;
	cout << "\n";
}

bool Player::isPlayerOutside() {
	return isOutside;
}