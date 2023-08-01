#pragma once

#include "../Templates/Singleton.h"
#include <iostream>

class AssetManager final : public Singleton<AssetManager> 
{
private:
    int someVal = 0;

public:
    AssetManager(token);
    ~AssetManager();

    void use();
};