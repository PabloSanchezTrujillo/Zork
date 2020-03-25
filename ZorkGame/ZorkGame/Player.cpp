#include "Player.h"

Player::Player() {
	inventory = list<Entity>();
	isOutside = false;
}

Player::Player(type _entityType, string _name, string _description, list<Entity> _inventory, Room* _location)
	: Creature(_entityType, _name, _description, _inventory, _location) {
	isOutside = false;
}

Player::Player(type _entityType, string _name, string _description, Room* _location)
	: Creature(_entityType, _name, _description, _location) {
	inventory = list<Entity>();
	isOutside = false;
}

Player::~Player() {
}

void Player::update() {
	cout << ">";
	cin >> action;
	cout << "\n";
	//cout << "Player action: " << action << endl;
	//cout << "\n";

	if(actionToPlayerAction()) {
		switch(playerAction) {
		case playerActions::search:
			searchRoom();
			break;

		case playerActions::drop:
			dropItem();
			break;

		case playerActions::use:
			useItem();
			break;

		default:
			cout << "Ooops this should not happen. Not a valid player action" << endl;
		}
	}
	else {
		checkExit();
	}
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

void Player::searchRoom() {
	if(location->getItems().size() > 0) {
		Entity item = location->getItems().front();
		inventory.push_back(item);
		location->popFront();

		cout << "You found a: " << item.getName() << ". " << item.getDescription() << endl;
		cout << "\n";
	}
	else {
		cout << "There's nothing in the room" << endl;
		cout << "\n";
	}
}

void Player::dropItem() {
	if(inventory.size() > 0) {
		string itemName;

		cout << "What item do you want to drop?" << endl;
		cout << "[ ";
		for(Entity item : inventory) {
			cout << item.getName() << ", ";
		}
		cout << "]" << endl;
		cout << "\n";
		cout << ">";
		cin >> itemName;
		dropTheItem(itemName);
	}
	else {
		cout << "You don't have anything in your inventory" << endl;
		cout << "\n";
	}
}

void Player::dropTheItem(string itemName) {
	for(Entity item : inventory) {
		if(itemName == item.getName()) {
			cout << "\n";
			cout << "You drop the " << item.getName() << " in the " << location->getName() << endl;
			cout << "\n";

			location->pushBack(item);
			inventory.remove(item);

			return;
		}
	}

	cout << "\n";
	cout << "You don't have that item in your inventory" << endl;
	cout << "\n";
}

void Player::useItem() {
	cout << "Use item" << endl;
	cout << "\n";
}

bool Player::isPlayerOutside() {
	return isOutside;
}