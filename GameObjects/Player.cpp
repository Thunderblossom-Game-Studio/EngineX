#include "Player.h"
#include "../Globals/DeltaTime.h"
#include "../Core/InputManager.h"
#include <cmath>

Player::Player()
{
    InputManager::instance().BindKey(SDL_SCANCODE_W, InputManager::KeypressType::KEYHELD, std::bind(&Player::MoveForward, this));
    InputManager::instance().BindKey(SDL_SCANCODE_S, InputManager::KeypressType::KEYHELD, std::bind(&Player::MoveBackward, this));
    InputManager::instance().BindKey(SDL_SCANCODE_A, InputManager::KeypressType::KEYHELD, std::bind(&Player::MoveLeft, this));
    InputManager::instance().BindKey(SDL_SCANCODE_D, InputManager::KeypressType::KEYHELD, std::bind(&Player::MoveRight, this));

    InputManager::instance().BindKey(SDL_SCANCODE_LEFT, InputManager::KeypressType::KEYHELD, std::bind(&Player::RotateLeft, this));
    InputManager::instance().BindKey(SDL_SCANCODE_RIGHT, InputManager::KeypressType::KEYHELD, std::bind(&Player::RotateRight, this));
}

Player::~Player()
{}

void Player::MoveForward()
{
    double moveSpeed = DeltaTime::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _posX += _dirX * moveSpeed;
    _posY += _dirY * moveSpeed;
}

void Player::MoveBackward()
{
    double moveSpeed = DeltaTime::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _posX -= _dirX * moveSpeed;
    _posY -= _dirY * moveSpeed;
}

void Player::MoveLeft()
{
    double moveSpeed = DeltaTime::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _posX -= _planeX * moveSpeed;
    _posY -= _planeY * moveSpeed;
}

void Player::MoveRight()
{
    double moveSpeed = DeltaTime::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _posX += _planeX * moveSpeed;
    _posY += _planeY * moveSpeed;
}

void Player::RotateLeft()
{
    double rotSpeed = DeltaTime::GetDeltaTime() * 3.0; //the constant value is in radians/second
    double oldDirX = _dirX;
    _dirX = _dirX * cos(rotSpeed) - _dirY * sin(rotSpeed);
    _dirY = oldDirX * sin(rotSpeed) + _dirY * cos(rotSpeed);
    double oldPlaneX = _planeX;
    _planeX = _planeX * cos(rotSpeed) - _planeY * sin(rotSpeed);
    _planeY = oldPlaneX * sin(rotSpeed) + _planeY * cos(rotSpeed);
}

void Player::RotateRight()
{
    double rotSpeed = DeltaTime::GetDeltaTime() * 3.0; //the constant value is in radians/second
    double oldDirX = _dirX;
    _dirX = _dirX * cos(-rotSpeed) - _dirY * sin(-rotSpeed);
    _dirY = oldDirX * sin(-rotSpeed) + _dirY * cos(-rotSpeed);
    double oldPlaneX = _planeX;
    _planeX = _planeX * cos(-rotSpeed) - _planeY * sin(-rotSpeed);
    _planeY = oldPlaneX * sin(-rotSpeed) + _planeY * cos(-rotSpeed);
}