#pragma once

#include <memory>
#include <map>

#include "Singleton.h"
#include "Level.h"

class LevelManager : public Singleton<LevelManager>
{
private:
    //std::map<const char*, std::shared_ptr<Level>> _levels;
    std::shared_ptr<Level> _level;

public:
    LevelManager(token) {};
    ~LevelManager() {};

    std::shared_ptr<Level> GetLevel();

    void LoadLevel(std::shared_ptr<Level> level);

    void RemoveLevel(const char* levelName);

    void UpdateLevel();

};