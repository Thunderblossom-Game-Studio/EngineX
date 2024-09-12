#include <iostream>

#include "Core/GameEngine.h"

int main() {
  std::cout << "Running main" << std::endl;
  GameEngine game;

  if (!game.IsRunning()) {
    std::cout << "Game::Init failed" << std::endl;
    return -1;
  }

  while (game.IsRunning()) {
    game.Update();
  }

  return 0;
}
