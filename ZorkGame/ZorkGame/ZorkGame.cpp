#include <iostream>
#include "World.h"

using namespace std;

int main()
{
	World* house = new World();
	string accion;

	cout << house->getRoom(3)->getName() << " - " << house->getRoom(3)->getDescription() << endl;
	cout << "\n";
	cout << house->getRoom(6)->getName() << " - " << house->getRoom(6)->getDescription() << endl;
	cout << "\n";
	cout << house->getRoom(10)->getName() << " - " << house->getRoom(10)->getDescription() << endl;
	cout << "\n";

	cout << ">";
	cin >> accion;

	cout << "Exit game" << endl;
	return 0;
}