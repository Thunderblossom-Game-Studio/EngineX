#pragma once

#include <vector>
#include <memory>
#include "Vector2.h"
#include "Component.h"

class BaseGameObject {
private:
    float _FixedUpdateTimer = 0.f;

protected:
    Vector2 _pos;
    Vector2 _dir;

    std::vector<std::unique_ptr<Component>> _components;

public:
    BaseGameObject(Vector2 position, Vector2 direction) : _pos(position), _dir(direction)
    {}

    template<class T>
    T* GetComponent()
    {
        for(auto& component : _components)
        {
            T* castedComponent = dynamic_cast<T*>(component.get());
            if(castedComponent != nullptr)
            {
                return castedComponent;
            }
        }
        // If we reach this point, the component was not found
        return nullptr;
    }

    template<class T, typename... Args>
    T* AddComponent(Args&&... args)
    {
        static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

        // Check if the component already exists
        T* existingComponent = GetComponent<T>();
        if(existingComponent != nullptr)
        {
            return existingComponent;
        }

        // Create a new component of type T and add it to the list of components
        _components.push_back(std::make_unique<T>(std::forward<Args>(args)...));

        // Return the newly created component
        return dynamic_cast<T*>(_components.back().get());
    }

    template<class T>
    void RemoveComponent()
    {
        for(auto it = _components.begin(); it != _components.end(); ++it)
        {
            T* castedComponent = dynamic_cast<T*>(it->get());
            if(castedComponent != nullptr)
            {
                _components.erase(it);
                return;
            }
        }
    }

    virtual void Start() = 0;
    virtual void FixedUpdate();
    virtual void Update();
    virtual void LateUpdate();

    double GetPosX() const {return _pos.X;}
    double GetPosY() const {return _pos.Y;}
    Vector2 GetPos() const {return _pos;}

    double GetDirX() const {return _dir.X;}
    double GetDirY() const {return _dir.Y;}
    Vector2 GetDir() const {return _dir;}

    void SetPosX(double x) {_pos.X = x;}
    void SetPosY(double y) {_pos.Y = y;}
    void SetPos(Vector2 pos) {_pos = pos;}

    void SetDirX(double x) {_dir.X = x;}
    void SetDirY(double y) {_dir.Y = y;}
    void SetDir(Vector2 dir) {_dir = dir;}
};