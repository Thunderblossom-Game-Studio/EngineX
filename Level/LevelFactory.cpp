#include "LevelFactory.h"

LevelFactory::LevelFactory(token)
{}

LevelFactory::~LevelFactory()
{}

std::shared_ptr<Level> LevelFactory::CreateLevel()
{
    std::shared_ptr<Level> level = std::make_shared<Level>();
    return level;
}