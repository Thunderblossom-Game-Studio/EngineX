#include "Player.h"
#include "DeltaTime.h"
#include "InputManager.h"
#include "RenderInstanceManager.h"
#include <cmath>
#include <iostream>

// Component includes
#include "HealthComponent.h"

Player::Player()
    : BaseGameObject(Vector2(22.0, 11.5), Vector2(-1.0, 0.0))
{
    InputManager::instance().BindKey(SDL_SCANCODE_W, InputManager::KeypressType::KEYHELD, [this] { MoveForward(); });
    InputManager::instance().BindKey(SDL_SCANCODE_S, InputManager::KeypressType::KEYHELD, [this] { MoveBackward(); });
    InputManager::instance().BindKey(SDL_SCANCODE_A, InputManager::KeypressType::KEYHELD, [this] { MoveLeft(); });
    InputManager::instance().BindKey(SDL_SCANCODE_D, InputManager::KeypressType::KEYHELD, [this] { MoveRight(); });

    InputManager::instance().BindKey(SDL_SCANCODE_LEFT, InputManager::KeypressType::KEYHELD, [this] { RotateLeft(); });
    InputManager::instance().BindKey(SDL_SCANCODE_RIGHT, InputManager::KeypressType::KEYHELD, [this] { RotateRight(); });

    _camera = RenderInstanceManager::instance().GetRenderer(0)->GetCamera();
}

void Player::MoveForward()
{
    double moveSpeed = Time::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _pos.X += _dir.X * moveSpeed;
    _pos.Y += _dir.Y * moveSpeed;
}

void Player::MoveBackward()
{
    double moveSpeed = Time::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _pos.X -= _dir.X * moveSpeed;
    _pos.Y -= _dir.Y * moveSpeed;
}

void Player::MoveLeft()
{
    double moveSpeed = Time::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _pos.X -= _plane.X * moveSpeed;
    _pos.Y -= _plane.Y * moveSpeed;
}

void Player::MoveRight()
{
    double moveSpeed = Time::GetDeltaTime() * 5.0; //the constant value is in squares/second
    _pos.X += _plane.X * moveSpeed;
    _pos.Y += _plane.Y * moveSpeed;
}

void Player::RotateLeft()
{
    double rotSpeed = Time::GetDeltaTime() * 3.0; //the constant value is in radians/second
    double oldDirX = _dir.X;
    _dir.X = _dir.X * cos(rotSpeed) - _dir.Y * sin(rotSpeed);
    _dir.Y = oldDirX * sin(rotSpeed) + _dir.Y * cos(rotSpeed);
    double oldPlaneX = _plane.X;
    _plane.X = _plane.X * cos(rotSpeed) - _plane.Y * sin(rotSpeed);
    _plane.Y = oldPlaneX * sin(rotSpeed) + _plane.Y * cos(rotSpeed);
}

void Player::RotateRight()
{
    double rotSpeed = Time::GetDeltaTime() * 3.0; //the constant value is in radians/second
    double oldDirX = _dir.X;
    _dir.X = _dir.X * cos(-rotSpeed) - _dir.Y * sin(-rotSpeed);
    _dir.Y = oldDirX * sin(-rotSpeed) + _dir.Y * cos(-rotSpeed);
    double oldPlaneX = _plane.X;
    _plane.X = _plane.X * cos(-rotSpeed) - _plane.Y * sin(-rotSpeed);
    _plane.Y = oldPlaneX * sin(-rotSpeed) + _plane.Y * cos(-rotSpeed);
}

void Player::BeginPlay()
{
    BaseGameObject::BeginPlay();

    // Add Health Component
    AddComponent<HealthComponent>(this);
}

void Player::FixedUpdate()
{
    BaseGameObject::FixedUpdate();
}

void Player::Update()
{
    BaseGameObject::Update();

    _camera->SetPosition(_pos);
    _camera->SetDirection(_dir);
    _camera->SetPlane(_plane);
}

void Player::LateUpdate()
{
    BaseGameObject::LateUpdate();
}

