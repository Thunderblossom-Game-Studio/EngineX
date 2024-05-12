#pragma once
#include <vector>
#include <memory>

#include "BaseGameObject.h"
#include "Wall.h"
#include "Player.h"

class Level
{
private:
    std::vector<std::shared_ptr<Player>> _players;
    std::vector<std::shared_ptr<BaseGameObject>> _levelObjects;

    const int _mapWidth = 24;
    const int _mapHeight = 24;
    std::vector<std::vector<std::shared_ptr<Wall>>> _map;

public:
    Level() = default;

    int GetMapWidth() const {return _mapWidth;};
    int GetMapHeight() const {return _mapHeight;};

    std::vector<std::vector<std::shared_ptr<Wall>>> GetMap() {return _map;};
    void SetMap(const std::vector<std::vector<std::shared_ptr<Wall>>>& map) {_map = map;};

    void Update();

    void AddPlayer(const std::shared_ptr<Player>& player);
    void AddLevelObject(const std::shared_ptr<BaseGameObject>& object);

    std::vector<std::shared_ptr<Player>> GetPlayers() {return _players;};

    std::vector<std::shared_ptr<BaseGameObject>> GetLevelObjects() {return _levelObjects;};
};