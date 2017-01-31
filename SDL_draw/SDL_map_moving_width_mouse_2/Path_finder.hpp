#pragma once
#include "Node.hpp"

class Path_finder {
private:
  
public:
  std::vector<std::vector<int>> map;
  Path_finder(std::vector<std::vector<int>>& _map);
  std::string find_path(int& start_x, int& start_y, int& finish_x, int& finish_y);
  ~Path_finder();
};

