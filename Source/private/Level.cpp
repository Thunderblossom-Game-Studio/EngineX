#include "Level.h"
#include "BaseGameObject.h"

void Level::Update()
{
    // Update all players
    for(const auto& player : _players)
    {
        player->Update();
    }

    // Update all level objects
    for(const auto& gameObject : _levelObjects)
    {
        gameObject->Update();
    }
}

void Level::AddPlayer(const std::shared_ptr<Player>& player)
{
    _players.push_back(player);
}

void Level::AddLevelObject(const std::shared_ptr<BaseGameObject>& object)
{
    _levelObjects.push_back(object);
}
