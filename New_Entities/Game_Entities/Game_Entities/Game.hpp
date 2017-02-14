#pragma once

#include "Map.hpp"

class Game {
private:
  Game();
  static Game* game_instance;
public:
  Map* map = NULL;
  int from_json(json);
  void write_json_to_file(json);
  static Game* get_game_instance();
  ~Game();
};

