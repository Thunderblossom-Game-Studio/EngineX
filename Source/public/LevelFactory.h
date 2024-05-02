#pragma once

#include "Singleton.h"
#include "Level.h"

class LevelFactory : public Singleton<LevelFactory>
{  
public:
    LevelFactory(token);
    ~LevelFactory();

    std::shared_ptr<Level> CreateLevel();
};