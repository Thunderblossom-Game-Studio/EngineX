#include "LevelManager.h"

LevelManager::LevelManager(token) {}

LevelManager::~LevelManager() {}

std::shared_ptr<Level> LevelManager::GetLevel(const char* levelName)
{
    return _levels[levelName];
}

void LevelManager::AddLevel(const char* levelName, std::shared_ptr<Level> level)
{
    _levels.at(levelName) = level;
}

void LevelManager::RemoveLevel(const char* levelName)
{
    _levels.erase(levelName);
}