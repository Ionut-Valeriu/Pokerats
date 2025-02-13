//
// Created by ionut on 22.10.2024.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

////////// INCLUDE SECTION //////////
#include <map>
#include <string>
#include <vector>
#include <memory>

#include "Entity.h"
#include "LevelLoader.h"
#include "Player.h"

////////// DESCRIPTION //////////

/// this class manage the entities in those modes:
/// - create new entities and:
/// --1 add them to a vector of active entities
/// --2 add them to a vector inside of map, by their draw level
/// --3 remove dead entities and resize some of the vectors
/// --4 give each entity a unique id (m_entitiesSpawned)
///     this variable counts how many entities we have spawned in the entire game

////////// SHORTCUTS //////////
typedef std::vector<std::shared_ptr<Entity> > EntityVec;
// typedef std::map<std::string, EntityVec> EntityMap;
typedef std::map<size_t, EntityVec> EntityDrawMap;

////////// DEFINITION OF CLASS //////////
class EntityManager {
    // size 48
    EntityDrawMap m_entityDrawMap;

    // size 24
    EntityVec m_entities; // vector to store all current entities
    EntityVec m_entitiesToAdd; // vector to store entities that will be added // this evicts some bugs

    // size 8
    static size_t m_entitiesSpawned;
    static size_t m_maxDrawLevel;

    static void removeDeadEntities(EntityVec &vec); // this is called in update

public:
    void update(); // adding and removing entities

    static size_t getEntityCount();

    const EntityVec &getEntities() { return m_entities; }
    const EntityVec &getEntitiesOnLevel(const size_t &level) { return m_entityDrawMap[level]; }

    // void setMaxDrawLevel(size_t maxDrawLevel) { m_maxDrawLevel = maxDrawLevel; }
    static size_t getMaxDrawLevel() { return m_maxDrawLevel; }

    std::shared_ptr<Player> load(const std::string &fileName, sf::RenderWindow &rWindow);
};

#endif //ENTITYMANAGER_H
