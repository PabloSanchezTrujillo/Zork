#ifndef ENTITY_H
#define ENTITY_H

#include<iostream>
#include<list>

using namespace std;

class Entity {
public:
	enum type {
		player,
		enemy,
		room,
		exit,
		item
	};

private:
	type entityType;
	string name;
	string description;
	list<Entity*> contains;

public:
	Entity(type, string, string, list<Entity*>);
	~Entity();
	virtual void update();
	string getName();
	string getDescription();
};

#endif // !ENTITY_H