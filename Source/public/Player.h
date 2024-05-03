#pragma once

#include "BaseGameObject.h"
#include "Camera.h"
#include "Vector2.h"

class Player : public BaseGameObject
{
private:
    Vector2 _plane = Vector2(0, 0.66);

    Camera* _camera;

    void MoveForward();
    void MoveBackward();
    void MoveLeft();
    void MoveRight();

    void RotateLeft();
    void RotateRight();

public:
    Player();

    double GetPlaneX() const {return _plane.X;}
    double GetPlaneY() const {return _plane.Y;}

    void Start() override;
    void FixedUpdate() override;
    void Update() override;
    void LateUpdate() override;
};