#include "../public/ExampleGameObject.h"
#include <iostream>

#include "../public/InputManager.h"

ExampleGameObject::ExampleGameObject(float x, float y, float width, float height) : _width(width), _height(height)
{
    std::cout << "ExampleGameObject constructor" << std::endl;
    _x = x;
    _y = y;

    // Example of how to add a keybind
    InputManager::instance().BindKey(SDL_SCANCODE_A, InputManager::KeypressType::KEYDOWN, std::bind(&ExampleGameObject::SomeExampleKeybind, this));
}

ExampleGameObject::~ExampleGameObject()
{
    std::cout << "ExampleGameObject destructor" << std::endl;
}

void ExampleGameObject::SomeExampleKeybind()
{
    std::cout << "ExampleGameObject::SomeExampleKeybind" << std::endl;
}