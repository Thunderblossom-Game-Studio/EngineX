#include "DeltaTime.h"

std::chrono::steady_clock::time_point Time::_lastTime = std::chrono::steady_clock::now();
std::chrono::steady_clock::time_point Time::_currentTime = std::chrono::steady_clock::now();

float Time::GetDeltaTime()
{
    return std::chrono::duration_cast<std::chrono::duration<float>>(_currentTime - _lastTime).count();
}

void Time::UpdateDeltaTime()
{
    _lastTime = _currentTime;
    _currentTime = std::chrono::steady_clock::now();
}