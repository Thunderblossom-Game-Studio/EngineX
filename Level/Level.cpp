#include "Level.h"
#include "../GameObjects/Player.h"
#include "TempTestLevel.h"

Level::Level()
{
    // Create the player
    _player = std::make_shared<Player>();

    // Read the map data from TempTestLevel.h and store it in _map
    for (int i = 0; i < _mapHeight; i++)
    {
        std::vector<int> row;
        for (int j = 0; j < _mapWidth; j++)
        {
            row.push_back(worldMap[i][j]);
        }
        _map.push_back(row);
    }
}

Level::~Level()
{}