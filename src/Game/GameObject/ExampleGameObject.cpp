#include "ExampleGameObject.h"
#include <iostream>

#include "Core/InputManager.h"

ExampleGameObject::ExampleGameObject(Vector2 position, Vector2 direction, float width, float height)
    : _width(width), _height(height), BaseGameObject(position, direction)
{}

ExampleGameObject::~ExampleGameObject()
{}

void ExampleGameObject::SomeExampleKeybind()
{}

void ExampleGameObject::Update()
{}
