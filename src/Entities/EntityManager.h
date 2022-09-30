#pragma once
#include <string>
#include <map>
#include "Entity.h"

/**
	[ EntityManager ]
	An EntityManager holds an ordered map of entity pointers
	to be updated and drawn each cycle. Each entity can be looked
	up by key and the manager facilitates collision checking
	between them.

	Any entity pointer added to the manager is deleted when the
	entity is removed, the map is cleared, or the manager is destroyed.
*/
class EntityManager
{
public:
	~EntityManager();

	// Add an entity to be managed by the EntityManager
	void AddEntity(std::string id, Entity* entity);
	// Get an entity from the EntityManager by key
	// Returns nullptr if it is not found
	Entity* GetEntity(std::string id);
	// If the entity with the given id exists, it is deleted
	// and removed from the map
	void RemoveEntity(std::string id);
	// All entities are deleted and removed from the map
	void ClearEntities();

	// Checks collision between two entities with the given ids
	bool CheckCollision(std::string id1, std::string id2);

	void Update(float dt);
	void Draw();
private:
	// Ordered map of entities that the EntityManager is responsible for
	std::map<std::string, Entity*> entities;
};

