#include "LevelManager.h"

void LevelManager::LoadLevel(std::unique_ptr<Level> level)
{
    _level = std::move(level);
}

void LevelManager::UpdateLevel()
{
    _level->Update();
}

void LevelManager::BeginPlay()
{
    // Call BeginPlay on all players
    for(const auto& player : _level->GetPlayers())
    {
        player->BeginPlay();
    }

    // Call BeginPlay on all level objects
    for(const auto& gameObject : _level->GetLevelObjects())
    {
        gameObject->BeginPlay();
    }
}

void LevelManager::UnloadLevel()
{
    _level.reset();
}

std::vector<std::vector<std::shared_ptr<Wall>>> LevelManager::GetMap()
{
    return _level->GetMap();
}
