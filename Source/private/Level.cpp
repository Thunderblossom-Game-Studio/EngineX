#include "Level.h"
#include "TempTestLevel.h"

Level::Level()
{
    // Create the player
    _player = std::make_shared<Player>();

    // Read the map data from TempTestLevel.h and store it in _map as either walls or nullptrs (empty space)
    for(int i = 0; i < _mapHeight; i++)
    {
        std::vector<Wall*> row;
        for(int j = 0; j < _mapWidth; j++)
        {
            if(worldMap[i][j])
            {
                row.push_back(new Wall(worldMap[i][j]));
            }
            else
            {
                row.push_back(nullptr);
            }
        }
        _map.push_back(row);
    }

}

Level::~Level()
{
    // Clear the map
    for(auto& row : _map)
    {
        for(auto& gameObject : row)
        {
            if(gameObject)
            {
                delete gameObject;
            }
        }
    }
}

void Level::Update()
{
    _player->Update();
    for(const auto& gameObject : _levelObjects)
    {
        gameObject->Update();
    }
}
