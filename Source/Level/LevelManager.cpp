#include "LevelManager.h"

std::shared_ptr<Level> LevelManager::GetLevel()
{
    return _level;
}

void LevelManager::LoadLevel(std::shared_ptr<Level> level)
{
    _level = level;
}

void LevelManager::RemoveLevel(const char* levelName)
{
    _level = nullptr;
}

void LevelManager::UpdateLevel()
{
    _level->Update();
}
