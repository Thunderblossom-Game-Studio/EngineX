#pragma once

#include "../Templates/Singleton.h"

class GameRenderer;

class Game final : public Singleton<Game>
{
private:
    bool _running = false;

public:
    Game(token);
    ~Game();

    bool Init();
    void Update();
    bool IsRunning() const { return _running; }
};