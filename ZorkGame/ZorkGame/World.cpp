#include "World.h"
#include "Room.h"
#include "Player.h"
#include<list>

World::World() {
	list<Entity*> list;
	Room* attic = new Room(Entity::type::room, "Attic", "You woke up in the attic of the house", list);
	Room* corridorTop = new Room(Entity::type::room, "Corridor second floor", "The corridor of the second floor", list);
	Room* bedroom = new Room(Entity::type::room, "Bedroom", "The bedroom of the house", list);
	Room* bathroomTop = new Room(Entity::type::room, "Bathroom second floor", "The bedroom's bathroom", list);
	Room* stairs = new Room(Entity::type::room, "Stairs to second floor", "The stairs between the first and the second floor", list);
	Room* hall = new Room(Entity::type::room, "The house main hall", "The house main hall, so close to the outside!!", list);
	Room* corridorBot = new Room(Entity::type::room, "Corridor first floor", "The corridor of the first floor", list);
	Room* livingRoom = new Room(Entity::type::room, "The house living room", "The house living room, it's nice here", list);
	Room* kitchen = new Room(Entity::type::room, "The house kithcen", "The house kitchen, a bit dirty but is ok", list);
	Room* bathroomBot = new Room(Entity::type::room, "Bathroom of the first floor", "The bathroom of the first floor", list);
	Room* basement = new Room(Entity::type::room, "The basement", "The house basement, so dark and creepy down there...", list);
	Room* outside = new Room(Entity::type::room, "Outside", "Outside, finally I'm free!!", list);

	entities.push_back(attic);
	entities.push_back(corridorTop);
	entities.push_back(bedroom);
	entities.push_back(bathroomTop);
	entities.push_back(stairs);
	entities.push_back(hall);
	entities.push_back(corridorBot);
	entities.push_back(livingRoom);
	entities.push_back(kitchen);
	entities.push_back(bathroomBot);
	entities.push_back(basement);
	entities.push_back(outside);
}

World::World(vector<Entity*> _entities) {
	entities = _entities;
}

World::~World() {
}

Entity* World::getEntity(int index)
{
	return entities.at(index);
}