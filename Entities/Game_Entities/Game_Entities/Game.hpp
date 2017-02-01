#pragma once

#include "LevelMap.hpp"


class Game {
private:
  static Game* game_instance;
  Game();
public: 
  LevelMap game_LevelMap;
  vector<vector<int>> tile_map;
  static Game* get_game_instance();
};
