#pragma once

#include "Map.hpp"

class Game {
private:
  Game();
  static Game* game_instance;
public:
  Map* map = NULL;
  static Game* get_game_instance();
  ~Game();
};

