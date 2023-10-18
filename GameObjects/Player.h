#pragma once

#include "BaseGameObject.h"

class Player : public BaseGameObject
{
private:
    double _posX = 22, _posY = 12;  //x and y start position
    double _dirX = -1, _dirY = 0; //initial direction vector
    double _planeX = 0, _planeY = 0.66; //the 2d raycaster version of camera plane

    void MoveForward();
    void MoveBackward();
    void MoveLeft();
    void MoveRight();

    void RotateLeft();
    void RotateRight();

public:
    Player();
    ~Player();

    double GetPosX() {return _posX;}
    double GetPosY() {return _posY;}

    double GetPlaneX() {return _planeX;}
    double GetPlaneY() {return _planeY;}

    double GetDirX() {return _dirX;}
    double GetDirY() {return _dirY;}
};