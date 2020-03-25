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
	list<Entity> contains;

public:
	Entity();
	Entity(type, string, string, list<Entity>);
	Entity(type, string, string);
	~Entity();
	virtual void update();
	string getName();
	string getDescription();
	list<Entity> getItems();
	void popFront();
	void pushBack(Entity);
	bool operator == (const Entity& entity) const { return entity.name == name; }
	bool operator != (const Entity& entity) const { return !operator==(entity); }
};

#endif // !ENTITY_H