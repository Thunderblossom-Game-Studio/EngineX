#include "BaseGameObject.h"
#include "DeltaTime.h"
#include "Config.h"

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
    _FixedUpdateTimer += Time::GetDeltaTime();
    if (_FixedUpdateTimer >= PHYSICS_TIMESTEP)
    {
        FixedUpdate();
        _FixedUpdateTimer = 0.0f;
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