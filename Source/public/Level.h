#pragma once
#include <vector>
#include <memory>

#include "BaseGameObject.h"
#include "Wall.h"
#include "Player.h"

class Level
{
private:
    std::shared_ptr<Player> _player;
    std::vector<std::shared_ptr<BaseGameObject>> _levelObjects;

    const int _mapWidth = 24;
    const int _mapHeight = 24;
    std::vector<std::vector<Wall*>> _map;

public:
    Level();
    ~Level();

    std::vector<std::vector<Wall*>> GetMap() {return _map;};
    int GetMapWidth() {return _mapWidth;};
    int GetMapHeight() {return _mapHeight;};

    void Update();


    std::shared_ptr<Player> GetPlayer() {return _player;};
};