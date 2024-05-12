#pragma once

#include <vector>
#include <memory>
#include "Vector2.h"
#include "Component.h"

class BaseGameObject {
private:
    float _fixedUpdateTimer = 0.f;

    static std::vector<std::weak_ptr<BaseGameObject>> _gameObjects;

protected:
    Vector2 _pos;
    Vector2 _dir;

    std::vector<std::unique_ptr<Component>> _components;

public:
    BaseGameObject(Vector2 position, Vector2 direction);

    // Returns the first matching component
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

    // Adds a new component of type T to the object
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

    // Removes the first matching component
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

    // Returns a vector of objects with the specified component
    template<class T>
    static std::vector<BaseGameObject> GetObjectsWithComponent()
    {
        std::vector<T*> objects;
        for(auto& gameObject : _gameObjects)
        {
            T* component = gameObject.lock()->GetComponent<T>();
            if(component != nullptr)
            {
                objects.push_back(gameObject);
            }
        }
        return objects;
    }

    // Returns the first object with the specified component
    template <class T>
    static std::weak_ptr<BaseGameObject> GetObjectWithComponent()
    {
        for(auto& gameObject : _gameObjects)
        {
            auto obj = gameObject.lock();
            T* component = obj->GetComponent<T>();
            if(component != nullptr)
            {
                return obj;
            }
        }
        return {};
    }

    // Returns a newly created object of type T
    template <class T, typename... Args>
    static std::shared_ptr<T> Instantiate(Args&&... args)
    {
        static_assert(std::is_base_of<BaseGameObject, T>::value, "T must derive from BaseGameObject");

        std::shared_ptr<T> newObject = std::make_shared<T>(std::forward<Args>(args)...);
        _gameObjects.push_back(newObject);
        return newObject;
    }

    virtual void BeginPlay() {}
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
    void SetPos(double x, double y) {_pos = Vector2(x, y);}

    void SetDirX(double x) {_dir.X = x;}
    void SetDirY(double y) {_dir.Y = y;}
    void SetDir(Vector2 dir) {_dir = dir;}
    void SetDir(double x, double y) {_dir = Vector2(x, y);}
};