#include <iostream>
#include "World.h"

using namespace std;

int main()
{
	World* house = new World();

	cout << "You are in the: " << house->getPlayer()->getLocation()->getName() << ". "
		<< house->getPlayer()->getLocation()->getDescription() << endl;
	cout << "\n";

	// GameLoop
	while(!house->getPlayer()->isPlayerOutside()) {
		for(Entity* entity : house->getEntities()) {
			entity->update();
		}
	}

	cout << "The end." << endl;
	cout << "\n";
	system("pause");
	return 0;
}