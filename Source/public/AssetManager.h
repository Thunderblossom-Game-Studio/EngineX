#pragma once

#include "Singleton.h"
#include <iostream>

class AssetManager final : public Singleton<AssetManager> 
{
private:

public:
    AssetManager(token);
    ~AssetManager();
};