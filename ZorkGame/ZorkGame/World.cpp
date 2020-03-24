#include "World.h"
#include "Room.h"
#include "Player.h"
#include<list>

World::World() {
	CreateRooms();
	ConnectRooms();
	list<Item*> inventory;
	Player* _player = new Player(Entity::type::player, "Player", "The player", inventory, getRoom("Attic"));
	entities.push_back(_player);
	player = _player;
}

World::World(vector<Entity*> _entities) {
	entities = _entities;
}

World::~World() {
}

void World::createItems() {
	Item* lantern = new Item(Entity::type::item, "Lantern", "A lantern with enough batteries for some hours");
	Item* bedroomKey = new Item(Entity::type::item, "Bedroom key", "A key that seems to open the bedroom");
	Item* maindoorKey = new Item(Entity::type::item, "A big, old key", "What will open this key?");

	houseItems.push_back(lantern);
	houseItems.push_back(bedroomKey);
	houseItems.push_back(maindoorKey);

	for(Item* item : houseItems) {
		entities.push_back(item);
	}
}

Item* World::getItem(string itemName) {
	for(Item* item : houseItems) {
		if(itemName == item->getName()) {
			return item;
		}
	}

	return nullptr;
}

void World::CreateRooms() {
	list<Entity*> itemsList;

	Room* attic = new Room(Entity::type::room, "Attic", "You woke up in the attic of a house", itemsList, true);
	Room* corridorTop = new Room(Entity::type::room, "Corridor second floor", "The corridor of the second floor", itemsList, false);
	itemsList.push_back(getItem("Lantern"));
	Room* bedroom = new Room(Entity::type::room, "Bedroom", "The bedroom of the house", itemsList, false);
	itemsList.clear();
	Room* bathroomTop = new Room(Entity::type::room, "Bathroom second floor", "The bedroom's bathroom", itemsList, false);
	Room* stairs = new Room(Entity::type::room, "Stairs", "The stairs between the first and the second floor", itemsList, false);
	Room* hall = new Room(Entity::type::room, "Hall", "The house main hall, so close to the outside!!", itemsList, false);
	Room* corridorBot = new Room(Entity::type::room, "Corridor first floor", "The corridor of the first floor", itemsList, false);
	itemsList.push_back(getItem("Bedroom key"));
	Room* livingRoom = new Room(Entity::type::room, "Living room", "The house living room, it's nice here", itemsList, false);
	itemsList.clear();
	Room* kitchen = new Room(Entity::type::room, "Kitchen", "The house kitchen, a bit dirty but is ok", itemsList, false);
	Room* bathroomBot = new Room(Entity::type::room, "Bathroom first floor", "The bathroom of the first floor", itemsList, false);
	itemsList.push_back(getItem("A big, old key"));
	Room* basement = new Room(Entity::type::room, "Basement", "The house basement, so dark and creepy down there...", itemsList, false);
	itemsList.clear();
	Room* outside = new Room(Entity::type::room, "Outside", "Outside, finally I'm free!!", itemsList, false);

	houseRooms.push_back(attic);
	houseRooms.push_back(corridorTop);
	houseRooms.push_back(bedroom);
	houseRooms.push_back(bathroomTop);
	houseRooms.push_back(stairs);
	houseRooms.push_back(hall);
	houseRooms.push_back(corridorBot);
	houseRooms.push_back(livingRoom);
	houseRooms.push_back(kitchen);
	houseRooms.push_back(bathroomBot);
	houseRooms.push_back(basement);
	houseRooms.push_back(outside);

	for(Room* room : houseRooms) {
		entities.push_back(room);
	}
}

void World::ConnectRooms() {
	Exit* attic_corridorTop = new Exit(Entity::type::exit, "Attic-CorridorTop", "Exit from attic to corridorTop", Exit::down, getRoom("Attic"), getRoom("Corridor second floor"));
	Exit* corridorTop_attic = new Exit(Entity::type::exit, "CorridorTop-Attic", "Exit from corridorTop to attic", Exit::up, getRoom("Corridor second floor"), getRoom("Attic"));
	Exit* corridorTop_bedroom = new Exit(Entity::type::exit, "CorridorTop-Bedroom", "Exit from corridorTop to bedroom", Exit::east, getRoom("Corridor second floor"), getRoom("Bedroom"));
	Exit* bedroom_corridorTop = new Exit(Entity::type::exit, "Bedroom-CorridorTop", "Exit from bedroom to corridorTop", Exit::west, getRoom("Bedroom"), getRoom("Corridor second floor"));
	Exit* corridorTop_bathroomTop = new Exit(Entity::type::exit, "CorridorTop-BathroomTop", "Exit from corridorTop to bathroom", Exit::south, getRoom("Corridor second floor"), getRoom("Bathroom second floor"));
	Exit* bathroomTop_corridorTop = new Exit(Entity::type::exit, "BathroomTop-CorridorTop", "Exit from bathroom to corridorTop", Exit::north, getRoom("Bathroom second floor"), getRoom("Corridor second floor"));
	Exit* bedroom_bathroomTop = new Exit(Entity::type::exit, "Bedroom-BathroomTop", "Exit from bedroom to bathroom", Exit::south, getRoom("Bedroom"), getRoom("Bathroom second floor"));
	Exit* bathroomTop_bedroom = new Exit(Entity::type::exit, "BathroomTop-Bedroom", "Exit from bathroom to bedroom", Exit::east, getRoom("Bathroom second floor"), getRoom("Bedroom"));
	Exit* corridorTop_stairs = new Exit(Entity::type::exit, "CorridorTop-Stairs", "Exit from corridorTop to stairs", Exit::west, getRoom("Corridor second floor"), getRoom("Stairs"));
	Exit* stairs_corridorTop = new Exit(Entity::type::exit, "Stairs-CorridorTop", "Exit from stairs to corridorTop", Exit::up, getRoom("Stairs"), getRoom("Corridor second floor"));
	Exit* stairs_hall = new Exit(Entity::type::exit, "Stairs-Hall", "Exit from stairs to main hall", Exit::down, getRoom("Stairs"), getRoom("Hall"));
	Exit* hall_stairs = new Exit(Entity::type::exit, "Hall-Stairs", "Exit from main hall to stairs", Exit::east, getRoom("Hall"), getRoom("Stairs"));
	Exit* hall_corridorBot = new Exit(Entity::type::exit, "Hall-CorridorBot", "Exit from hall to corridorBot", Exit::south, getRoom("Hall"), getRoom("Corridor first floor"));
	Exit* corridorBot_hall = new Exit(Entity::type::exit, "CorridorBot-Hall", "Exit from corridorBot to hall", Exit::north, getRoom("Corridor first floor"), getRoom("Hall"));
	Exit* hall_outside = new Exit(Entity::type::exit, "Hall-Outside", "Exit from hall to outside", Exit::north, getRoom("Hall"), getRoom("Outside"));
	Exit* outside_hall = new Exit(Entity::type::exit, "Outside-Hall", "Exit from outside to hall", Exit::south, getRoom("Outside"), getRoom("Hall"));
	Exit* hall_livingRoom = new Exit(Entity::type::exit, "Hall-LivingRoom", "Exit from hall to living room", Exit::west, getRoom("Hall"), getRoom("Living room"));
	Exit* livingRoom_hall = new Exit(Entity::type::exit, "LivingRoom-Hall", "Exit from living room to hall", Exit::north, getRoom("Living room"), getRoom("Hall"));
	Exit* corridorBot_livingRoom = new Exit(Entity::type::exit, "CorridorBot-LivingRoom", "Exit from corridorBot to living room", Exit::west, getRoom("Corridor first floor"), getRoom("Living room"));
	Exit* livingRoom_corridorBot = new Exit(Entity::type::exit, "LivingRoom-CorridorBot", "Exit from living room to corridorBot", Exit::east, getRoom("Living room"), getRoom("Corridor first floor"));
	Exit* corridorBot_bathroomBot = new Exit(Entity::type::exit, "CorridorBot-BathroomBot", "Exit from corridorBot to bathroomBot", Exit::east, getRoom("Corridor first floor"), getRoom("Bathroom first floor"));
	Exit* bathroomBot_corridorBot = new Exit(Entity::type::exit, "BathroomBot-CorridorBot", "Exit from bathroomBot to corridorBot", Exit::west, getRoom("Bathroom first floor"), getRoom("Corridor first floor"));
	Exit* corridorBot_kitchen = new Exit(Entity::type::exit, "CorridorBot-Kitchen", "Exit from corridorBot to kitchen", Exit::south, getRoom("Corridor first floor"), getRoom("Kitchen"));
	Exit* kitchen_corridorBot = new Exit(Entity::type::exit, "Kitchen-CorridorBot", "Exit from kitchen to corridorBot", Exit::north, getRoom("Kitchen"), getRoom("Corridor first floor"));
	Exit* kitchen_basement = new Exit(Entity::type::exit, "Kitchen-Basement", "Exit from kitchen to basement", Exit::down, getRoom("Kitchen"), getRoom("Basement"));
	Exit* basement_kitchen = new Exit(Entity::type::exit, "Basement-Kitchen", "Exit from basement to kitchen", Exit::up, getRoom("Basement"), getRoom("Kitchen"));

	houseConnections.push_back(attic_corridorTop);
	houseConnections.push_back(corridorTop_attic);
	houseConnections.push_back(corridorTop_bedroom);
	houseConnections.push_back(bedroom_corridorTop);
	houseConnections.push_back(corridorTop_bathroomTop);
	houseConnections.push_back(bathroomTop_corridorTop);
	houseConnections.push_back(bedroom_bathroomTop);
	houseConnections.push_back(bathroomTop_bedroom);
	houseConnections.push_back(corridorTop_stairs);
	houseConnections.push_back(stairs_corridorTop);
	houseConnections.push_back(stairs_hall);
	houseConnections.push_back(hall_stairs);
	houseConnections.push_back(hall_corridorBot);
	houseConnections.push_back(corridorBot_hall);
	houseConnections.push_back(hall_outside);
	houseConnections.push_back(outside_hall);
	houseConnections.push_back(hall_livingRoom);
	houseConnections.push_back(livingRoom_hall);
	houseConnections.push_back(corridorBot_livingRoom);
	houseConnections.push_back(livingRoom_corridorBot);
	houseConnections.push_back(corridorBot_bathroomBot);
	houseConnections.push_back(bathroomBot_corridorBot);
	houseConnections.push_back(corridorBot_kitchen);
	houseConnections.push_back(kitchen_corridorBot);
	houseConnections.push_back(kitchen_basement);
	houseConnections.push_back(basement_kitchen);
}

Room* World::getRoom(string roomName) {
	for(Room* room : houseRooms)
	{
		if(room->getName() == roomName) {
			return room;
		}
	}

	return nullptr;
}

vector<Entity*> World::getEntities() {
	return entities;
}

Player* World::getPlayer() {
	return player;
}