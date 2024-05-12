#pragma once

#include "Singleton.h"
#include "Level.h"

class LevelFactory : public Singleton<LevelFactory>
{
private:
    LevelFactory() = default;

public:
    static std::unique_ptr<Level> CreateLevel();

};