#pragma once

#include "Vector2.h"

class Camera {
private:
    Vector2 _position;
    Vector2 _direction;
    Vector2 _plane;

public:
    Camera(Vector2 position, Vector2 direction, Vector2 plane);
    ~Camera() = default;

    Vector2 GetPosition() { return _position; }
    Vector2 GetDirection() { return _direction; }
    Vector2 GetPlane() { return _plane; }

    void SetPosition(Vector2 position) { _position = position; }
    void SetPosition(float x, float y) { _position = Vector2(x, y); }

    void SetDirection(Vector2 direction) { _direction = direction; }
    void SetDirection(float x, float y) { _direction = Vector2(x, y); }

    void SetPlane(Vector2 plane) { _plane = plane; }
    void SetPlane(float x, float y) { _plane = Vector2(x, y); }
};
