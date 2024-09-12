#pragma once

class Component {
private:
    class BaseGameObject* _owner;
    bool _bIsEnabled = true;
    bool _bShouldTick = true;

public:
    Component(BaseGameObject* owner, bool bShouldTick = true);


    virtual void FixedUpdate();
    virtual void Update();
    virtual void LateUpdate();

    BaseGameObject* GetOwner() const {return _owner;}

    bool IsEnabled() const {return _bIsEnabled;}
    void SetEnabled(bool bIsEnabled) {_bIsEnabled = bIsEnabled;}

    bool ShouldTick() const {return _bShouldTick;}
    void SetShouldTick(bool bShouldTick) {_bShouldTick = bShouldTick;}
};