#pragma once

#include <memory>
#include <map>

#include "../Templates/Singleton.h"
#include "Level.h"

class LevelManager : public Singleton<LevelManager>
{
private:
    std::map<const char*, std::shared_ptr<Level>> _levels;

public:
    LevelManager(token);
    ~LevelManager();

    std::shared_ptr<Level> GetLevel(const char* levelName);

    void AddLevel(const char* levelName, std::shared_ptr<Level> level);

    void RemoveLevel(const char* levelName);

};