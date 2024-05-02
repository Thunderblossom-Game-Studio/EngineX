#pragma once

#include "BaseGameObject.h"
#include "Camera.h"
#include "../Core/FVector2.h"

class Player : public BaseGameObject
{
private:
    //double _posX = 22, _posY = 12;  //x and y start position
    //double _dirX = -1, _dirY = 0; //initial direction vector
    //double _planeX = 0, _planeY = 0.66; //the 2d raycaster version of camera plane

    // pos, dir and plane as FVector2
    FVector2 _pos = FVector2(22, 12);
    FVector2 _dir = FVector2(-1, 0);
    FVector2 _plane = FVector2(0, 0.66);

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