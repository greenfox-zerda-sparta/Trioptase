#pragma once
#include <utility>
#include <vector>
#include "Field.hpp"
#include "Troop.hpp"
#include "Building.hpp"

using std::vector;

class Game {
private:
  Game();
  static Game* game_instance;
  void fill_tile_map();
  Field empty_field;
public: 
  const int map_size = 30;
  vector<vector<MapNode>> nodes;
  vector<vector<int>> tile_map;
  vector<vector<int>> path_map; // 0free 1'not stepable'
  vector<std::pair<int, int>> troop_path;
  static Game* get_game_instance();
};
