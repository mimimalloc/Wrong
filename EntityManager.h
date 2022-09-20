#pragma once
#include <string>
#include <map>
#include "Entity.h"

class EntityManager
{
public:
	~EntityManager();

	void AddEntity(std::string id, Entity* entity);
	Entity* GetEntity(std::string id);
	void RemoveEntity(std::string id);
	void ClearEntities();

	bool CheckCollision(std::string id1, std::string id2);

	void Update(float dt);
	void Draw();
private:
	std::map<std::string, Entity*> entities;
};

