#pragma once

#include "../Templates/Singleton.h"
#include "Level.h"

class LevelFactory : public Singleton<LevelFactory>
{  
public:
    LevelFactory();
    ~LevelFactory();

    Level* CreateLevel();
};