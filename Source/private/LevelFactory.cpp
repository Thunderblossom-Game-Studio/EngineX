#include "LevelFactory.h"
#include "TempTestLevel.h"

std::unique_ptr<Level> LevelFactory::CreateLevel()
{
    std::unique_ptr<Level> level = std::make_unique<Level>();

    // Create GameObjects
    auto player = BaseGameObject::Instantiate<Player>();
    level->AddPlayer(player);

    // Create Map from TempTestLevel, storing either wall or empty space
    std::vector<std::vector<std::shared_ptr<Wall>>> map;
    for(int i = 0; i < 24; i++)
    {
        std::vector<std::shared_ptr<Wall>> row;
        for(int j = 0; j < 24; j++)
        {
            if(worldMap[i][j])
            {
                row.push_back(std::make_shared<Wall>(worldMap[i][j]));
            }
            else
            {
                row.push_back(nullptr);
            }
        }
        map.push_back(row);
    }
    level->SetMap(map);

    return std::move(level);
}