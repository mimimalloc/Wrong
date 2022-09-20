#include "EntityManager.h"

EntityManager::~EntityManager()
{
	ClearEntities();
}

void EntityManager::AddEntity(std::string id, Entity* entity)
{
	entities[id] = entity;
}

Entity* EntityManager::GetEntity(std::string id)
{
	if (entities.count(id)) {
		return entities[id];
	}
	else {
		return nullptr;
	}
}

void EntityManager::RemoveEntity(std::string id)
{
	if (entities.count(id)) {
		delete entities[id];
		entities.erase(id);
	}
}

void EntityManager::ClearEntities()
{
	// The entity manager is in charge of deleting the entities
	// that it holds pointers to
	for (auto entity : entities) {
		delete entity.second;
	}
	entities.clear();
}

bool EntityManager::CheckCollision(std::string id1, std::string id2)
{
	if (entities.count(id1) && entities.count(id2)) {
		Entity* entity1 = GetEntity(id1);
		Entity* entity2 = GetEntity(id2);
		return CheckCollisionRecs(entity1->GetRect(), entity2->GetRect());
	}
	else {
		return false;
	}
	
}

void EntityManager::Update(float dt)
{
	for (auto entity : entities) {
		entity.second->Update(dt);
	}
}

void EntityManager::Draw()
{
	for (auto entity : entities) {
		entity.second->Draw();
	}
}
