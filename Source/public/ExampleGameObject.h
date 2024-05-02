#pragma once

#include "BaseGameObject.h"
#include "IRenderableObject.h"
#include "ICollidableObject.h"

class ExampleGameObject final : public BaseGameObject, public IRenderableObject, public ICollidableObject
{
private:
    float _width = 0;
    float _height = 0;

public:
    ExampleGameObject(float x, float y, float width, float height);
    ~ExampleGameObject();

    void SomeExampleKeybind();
};