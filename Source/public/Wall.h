#pragma once

#include "BaseGameObject.h"

class Wall
{
private:
    int color;

public:
    Wall(int color);

    int GetColour() const { return color; }
};