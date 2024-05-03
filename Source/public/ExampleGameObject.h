#pragma once

#include "BaseGameObject.h"
#include "IRenderableObject.h"
#include "ICollidableObject.h"

class ExampleGameObject final : public BaseGameObject
{
private:
    float _width = 0;
    float _height = 0;

    void Update() override;

public:
    ExampleGameObject(Vector2 position, Vector2 direction, float width, float height);
    ~ExampleGameObject();

    void SomeExampleKeybind();
};