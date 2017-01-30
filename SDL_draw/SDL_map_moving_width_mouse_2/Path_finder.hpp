#pragma once
#include "Node.hpp"

class Path_finder {
private:
public:
  Path_finder();
  std::string find_path(const int& start_x, const int& start_y, const int& finish_x, const int& finish_y);
  ~Path_finder();
};

