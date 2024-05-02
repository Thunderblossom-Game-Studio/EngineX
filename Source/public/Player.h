#pragma once

#include "BaseGameObject.h"
#include "Camera.h"
#include "Vector2.h"

class Player : public BaseGameObject
{
private:
    //double _posX = 22, _posY = 12;  //x and Y start position
    //double _dirX = -1, _dirY = 0; //initial direction vector
    //double _planeX = 0, _planeY = 0.66; //the 2d raycaster version of camera plane

    // pos, dir and plane as FVector2
    Vector2 _pos = Vector2(22, 12);
    Vector2 _dir = Vector2(-1, 0);
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
    ~Player();

    void Init();

    double GetPosX() {return _pos.X;}
    double GetPosY() {return _pos.Y;}

    double GetPlaneX() {return _plane.X;}
    double GetPlaneY() {return _plane.Y;}

    double GetDirX() {return _dir.X;}
    double GetDirY() {return _dir.Y;}

    void Update() override;
};