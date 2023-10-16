#pragma once
#include <vector>
#include <memory>

#include "../GameObjects/BaseGameObject.h"

class Level
{
private:
    // Player will be stored in 0th element until better solution is created
    std::vector<std::shared_ptr<BaseGameObject>> _levelObjects;

public:
    Level();
    ~Level();


    std::shared_ptr<BaseGameObject> GetPlayer() {return _levelObjects[0];};

};