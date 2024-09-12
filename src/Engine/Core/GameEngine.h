#pragma once

class GameEngine
{
private:
    bool _running = false;
    int _frameCount = 0;
    float _frameTime = 0.f;

public:
    GameEngine();

    void Update();
    bool IsRunning() const { return _running; }
};