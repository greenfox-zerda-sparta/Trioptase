#pragma once
#include <vector>
#include <utility>
#include "Node.hpp"
#include "../Entities/Game_logic.hpp"

using namespace std;

class Path_finder {
private:
  std::vector<std::vector<int>> tile_map;
  std::vector<std::vector<int>> temp_tile_map;
  std::vector<std::pair<unsigned short int, unsigned short int>> route;
  void reset_route();
public:
  Path_finder();  
  void find_path(const int& start_x, const int& start_y, const int& finish_x, const int& finish_y);
  void scratch_route_to_temp_map();
  void print_temp_map();
  ~Path_finder();
};

