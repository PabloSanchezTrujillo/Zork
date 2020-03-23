#include <iostream>
#include "World.h"

using namespace std;

int main()
{
	World* house = new World();

	cout << house->getEntity(3)->getName() << " - " << house->getEntity(3)->getDescription() << endl;
	cout << "\n";
	cout << house->getEntity(6)->getName() << " - " << house->getEntity(6)->getDescription() << endl;
	cout << "\n";
	cout << house->getEntity(10)->getName() << " - " << house->getEntity(10)->getDescription() << endl;
	cout << "\n";

	cout << "Exit game" << endl;
	return 0;
}