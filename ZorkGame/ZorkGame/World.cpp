#include "World.h"
#include "Room.h"
#include "Player.h"
#include<list>

World::World() {
	CreateRooms();
	ConnectRooms();
}

World::World(vector<Entity*> _entities) {
	entities = _entities;
}

World::~World() {
}

Room* World::getRoom(int index)
{
	return houseRooms.at(index);
}

void World::CreateRooms() {
	list<Entity*> list;
	Room* attic = new Room(Entity::type::room, "Attic", "You woke up in the attic of the house", list);
	Room* corridorTop = new Room(Entity::type::room, "Corridor second floor", "The corridor of the second floor", list);
	Room* bedroom = new Room(Entity::type::room, "Bedroom", "The bedroom of the house", list);
	Room* bathroomTop = new Room(Entity::type::room, "Bathroom second floor", "The bedroom's bathroom", list);
	Room* stairs = new Room(Entity::type::room, "Stairs", "The stairs between the first and the second floor", list);
	Room* hall = new Room(Entity::type::room, "Hall", "The house main hall, so close to the outside!!", list);
	Room* corridorBot = new Room(Entity::type::room, "Corridor first floor", "The corridor of the first floor", list);
	Room* livingRoom = new Room(Entity::type::room, "Living room", "The house living room, it's nice here", list);
	Room* kitchen = new Room(Entity::type::room, "Kitchen", "The house kitchen, a bit dirty but is ok", list);
	Room* bathroomBot = new Room(Entity::type::room, "Bathroom first floor", "The bathroom of the first floor", list);
	Room* basement = new Room(Entity::type::room, "Basement", "The house basement, so dark and creepy down there...", list);
	Room* outside = new Room(Entity::type::room, "Outside", "Outside, finally I'm free!!", list);

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
}

void World::ConnectRooms() {
	Exit* attic_corridorTop = new Exit(Entity::type::exit, "Attic-CorridorTop", "Exit from attic to corridorTop", Exit::down, findRoom("Attic"), findRoom("Corridor second floor"));
	Exit* corridorTop_attic = new Exit(Entity::type::exit, "CorridorTop-Attic", "Exit from corridorTop to attic", Exit::up, findRoom("Corridor second floor"), findRoom("Attic"));
	Exit* corridorTop_bedroom = new Exit(Entity::type::exit, "CorridorTop-Bedroom", "Exit from corridorTop to bedroom", Exit::east, findRoom("Bedroom"), findRoom("Corridor second floor"));
	Exit* bedroom_corridorTop = new Exit(Entity::type::exit, "Bedroom-CorridorTop", "Exit from bedroom to corridorTop", Exit::west, findRoom("Corridor second floor"), findRoom("Bedroom"));
	Exit* corridorTop_bathroomTop = new Exit(Entity::type::exit, "CorridorTop-BathroomTop", "Exit from corridorTop to bathroom", Exit::south, findRoom("Corridor second floor"), findRoom("Bathroom second floor"));
	Exit* bathroomTop_corridorTop = new Exit(Entity::type::exit, "BathroomTop-CorridorTop", "Exit from bathroom to corridorTop", Exit::north, findRoom("Bathroom second floor"), findRoom("Corridor second floor"));
	Exit* bedroom_bathroomTop = new Exit(Entity::type::exit, "Bedroom-BathroomTop", "Exit from bedroom to bathroom", Exit::south, findRoom("Bedroom"), findRoom("Bathroom second floor"));
	Exit* bathroomTop_bedroom = new Exit(Entity::type::exit, "BathroomTop-Bedroom", "Exit from bathroom to bedroom", Exit::east, findRoom("Bathroom second floor"), findRoom("Bedroom"));
	Exit* corridorTop_stairs = new Exit(Entity::type::exit, "CorridorTop-Stairs", "Exit from corridorTop to stairs", Exit::west, findRoom("Corridor second floor"), findRoom("Stairs"));
	Exit* stairs_corridorTop = new Exit(Entity::type::exit, "Stairs-CorridorTop", "Exit from stairs to corridorTop", Exit::up, findRoom("Stairs"), findRoom("Corridor second floor"));
	Exit* stairs_hall = new Exit(Entity::type::exit, "Stairs-Hall", "Exit from stairs to main hall", Exit::down, findRoom("Stairs"), findRoom("Hall"));
	Exit* hall_stairs = new Exit(Entity::type::exit, "Hall-Stairs", "Exit from main hall to stairs", Exit::east, findRoom("Hall"), findRoom("Stairs"));
	Exit* hall_corridorBot = new Exit(Entity::type::exit, "Hall-CorridorBot", "Exit from hall to corridorBot", Exit::south, findRoom("Hall"), findRoom("Corridor first floor"));
	Exit* corridorBot_hall = new Exit(Entity::type::exit, "CorridorBot-Hall", "Exit from corridorBot to hall", Exit::north, findRoom("Corridor first floor"), findRoom("Hall"));
	Exit* hall_outside = new Exit(Entity::type::exit, "Hall-Outside", "Exit from hall to outside", Exit::north, findRoom("Hall"), findRoom("Outside"));
	Exit* outside_hall = new Exit(Entity::type::exit, "Outside-Hall", "Exit from outside to hall", Exit::south, findRoom("Outside"), findRoom("Hall"));
	Exit* hall_livingRoom = new Exit(Entity::type::exit, "Hall-LivingRoom", "Exit from hall to living room", Exit::west, findRoom("Hall"), findRoom("Living room"));
	Exit* livingRoom_hall = new Exit(Entity::type::exit, "LivingRoom-Hall", "Exit from living room to hall", Exit::north, findRoom("Living room"), findRoom("Hall"));
	Exit* corridorBot_livingRoom = new Exit(Entity::type::exit, "CorridorBot-LivingRoom", "Exit from corridorBot to living room", Exit::west, findRoom("Corridor first floor"), findRoom("Living room"));
	Exit* livingRoom_corridorBot = new Exit(Entity::type::exit, "LivingRoom-CorridorBot", "Exit from living room to corridorBot", Exit::east, findRoom("Living room"), findRoom("Corridor first floor"));
	Exit* corridorBot_bathroomBot = new Exit(Entity::type::exit, "CorridorBot-BathroomBot", "Exit from corridorBot to bathroomBot", Exit::east, findRoom("Corridor first floor"), findRoom("Bathroom first floor"));
	Exit* bathroomBot_corridorBot = new Exit(Entity::type::exit, "BathroomBot-CorridorBot", "Exit from bathroomBot to corridorBot", Exit::west, findRoom("Bathroom first floor"), findRoom("Corridor first floor"));
	Exit* corridorBot_kitchen = new Exit(Entity::type::exit, "CorridorBot-Kitchen", "Exit from corridorBot to kitchen", Exit::south, findRoom("Corridor first floor"), findRoom("Kitchen"));
	Exit* kitchen_corridorBot = new Exit(Entity::type::exit, "Kitchen-CorridorBot", "Exit from kitchen to corridorBot", Exit::north, findRoom("Kitchen"), findRoom("Corridor first floor"));
	Exit* kitchen_basement = new Exit(Entity::type::exit, "Kitchen-Basement", "Exit from kitchen to basement", Exit::down, findRoom("Kitchen"), findRoom("Basement"));
	Exit* basement_kitchen = new Exit(Entity::type::exit, "Basement-Kitchen", "Exit from basement to kitchen", Exit::up, findRoom("Basement"), findRoom("Kitchen"));

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

Room* World::findRoom(string roomName) {
	for(Room* room : houseRooms)
	{
		if(room->getName() == roomName) {
			return room;
		}
	}

	return nullptr;
}