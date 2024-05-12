#pragma once

#include <memory>
#include <map>

#include "Singleton.h"
#include "Level.h"

class LevelManager : public Singleton<LevelManager>
{
private:
    std::unique_ptr<Level> _level;

public:
    LevelManager(token) {};

    void LoadLevel(std::unique_ptr<Level> level);
    void UnloadLevel();

    std::vector<std::vector<std::shared_ptr<Wall>>> GetMap();

    void BeginPlay();
    void UpdateLevel();

};