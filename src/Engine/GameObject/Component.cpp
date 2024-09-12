#include "Component.h"
#include "BaseGameObject.h"


Component::Component(BaseGameObject *owner, bool bShouldTick)
    : _owner(owner), _bShouldTick(bShouldTick)
{}

void Component::FixedUpdate()
{
    // Skip update if component is disabled or shouldn't tick
    if(!_bIsEnabled || !_bShouldTick)
    {
        return;
    }
}

void Component::Update()
{
    // Skip update if component is disabled or shouldn't tick
    if(!_bIsEnabled || !_bShouldTick)
    {
        return;
    }
}

void Component::LateUpdate()
{
    // Skip update if component is disabled or shouldn't tick
    if(!_bIsEnabled || !_bShouldTick)
    {
        return;
    }
}


