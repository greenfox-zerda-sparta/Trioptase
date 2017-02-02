#pragma once
#include <utility>
#include "LevelMap.hpp"


class Game {
private:
  static Game* game_instance;
  Game();
public: 
  const int map_size = 30;
  LevelMap game_LevelMap;
  vector<vector<int>> tile_map;
  vector<vector<int>> path_map; // 0free 1'not stepable'
  vector<std::pair<int, int>> troop_path;
  static Game* get_game_instance();
};
