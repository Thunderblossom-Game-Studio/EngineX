#pragma once

#include "BaseGameObject.h"

class Wall : public BaseGameObject
{
private:
    int color;

public:
    Wall(int color);
    ~Wall();

    void Update() override;
    int GetColour() const { return color; }
};