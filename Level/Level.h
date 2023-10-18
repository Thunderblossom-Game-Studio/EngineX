#pragma once
#include <vector>
#include <memory>

#include "../GameObjects/BaseGameObject.h"
#include "../GameObjects/Player.h"

class Level
{
private:
    std::shared_ptr<Player> _player;
    std::vector<std::shared_ptr<BaseGameObject>> _levelObjects;

    const static int _mapWidth = 24;
    const static int _mapHeight = 24;
    std::vector<std::vector<int>> _map;

public:
    Level();
    ~Level();

    std::vector<std::vector<int>> GetMap() {return _map;};
    int GetMapWidth() {return _mapWidth;};
    int GetMapHeight() {return _mapHeight;};


    std::shared_ptr<Player> GetPlayer() {return _player;};
};