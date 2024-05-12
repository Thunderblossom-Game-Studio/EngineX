#include "BaseGameObject.h"
#include "DeltaTime.h"
#include "Config.h"

std::vector<std::weak_ptr<BaseGameObject>> BaseGameObject::_gameObjects;

void BaseGameObject::FixedUpdate()
{
    // Handle Component Fixed Updates
    for (auto& component : _components)
    {
        component->FixedUpdate();
    }
}

void BaseGameObject::Update()
{
    // Handle fixed update
    _fixedUpdateTimer += Time::GetDeltaTime();
    if (_fixedUpdateTimer >= FIXED_UPDATE_RATE)
    {
        FixedUpdate();
        _fixedUpdateTimer = 0.0f;
    }

    // Handle Component Updates
    for (auto& component : _components)
    {
        component->Update();
    }
}

void BaseGameObject::LateUpdate()
{
    // Handle Component Late Updates
    for (auto& component : _components)
    {
        component->LateUpdate();
    }
}

BaseGameObject::BaseGameObject(Vector2 position, Vector2 direction)
{
    _pos = position;
    _dir = direction;

    _fixedUpdateTimer = 0.f;
}

