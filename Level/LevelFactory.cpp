#include "LevelFactory.h"

Level* LevelFactory::CreateLevel()
{
    return new Level();
}