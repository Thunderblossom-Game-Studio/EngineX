#pragma once

#include "Component.h"

class HealthComponent : public Component
{
private:
    int _health = 100;

public:
    HealthComponent(class BaseGameObject* Owner);

    void Damage(int damage) {_health -= damage;}
    void Heal(int heal) {_health += heal;}

    int GetHealth() const {return _health;}
};
