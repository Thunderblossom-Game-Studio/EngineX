#pragma once

#include "Singleton.h"

class GameRenderer;

class Game final : public Singleton<Game>
{
private:
    bool _running = false;
    int _frameCount = 0;
    float _frameTime = 0.f;

public:
    Game(token);
    ~Game();

    bool Init();
    void Update();
    bool IsRunning() const { return _running; }
};