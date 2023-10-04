#include "InputManager.h"
#include <SDL2/SDL.h>

InputManager::InputManager(token)
{
}

InputManager::~InputManager()
{
    UnbindAllKeys();
}

void InputManager::BindKey(SDL_Scancode key, KeypressType type, std::function<void()> callback)
{
    switch (type)
    {
    case KEYDOWN:
        _keyDownCallbacks[key] = callback;
        break;
    case KEYUP:
        _keyUpCallbacks[key] = callback;
        break;
    case KEYHELD:
        _keyHeldCallbacks[key] = callback;
        break;
    default:
        break;
    }
}

void InputManager::UnbindKey(SDL_Scancode key, KeypressType type)
{
    switch (type)
    {
    case KEYDOWN:
        _keyDownCallbacks.erase(key);
        break;
    case KEYUP:
        _keyUpCallbacks.erase(key);
        break;
    case KEYHELD:
        _keyHeldCallbacks.erase(key);
        break;
    default:
        break;
    }
}

void InputManager::UnbindAllKeys()
{
    _keyDownCallbacks.clear();
    _keyUpCallbacks.clear();
    _keyHeldCallbacks.clear();
}

void InputManager::Update()
{
    SDL_memcpy(_lastKeyStates, _keyStates, SDL_NUM_SCANCODES);
    _keyStates = SDL_GetKeyboardState(NULL);

    // Iterates keyDown callbacks and calls bound functions if key has been recently pressed
    for (auto& key : _keyDownCallbacks)
    {
        if (_keyStates[key.first] && !_lastKeyStates[key.first])
        {
            key.second();
        }
    }

    // Iterates keyUp callbacks and calls bound functions if key has been recently released
    for (auto& key : _keyUpCallbacks)
    {
        if (!_keyStates[key.first] && _lastKeyStates[key.first])
        {
            key.second();
        }
    }

    // Iterates keyHeld callbacks and calls bound functions if key is currently being held
    for (auto& key : _keyHeldCallbacks)
    {
        if (_keyStates[key.first])
        {
            key.second();
        }
    }
}