#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>
#include <vector>
#include "Node.hpp"

using namespace std;

class Path_finder {
private:
  std::vector<std::vector<int>> tile_map;
public:
  Path_finder(std::vector<std::vector<int>>& _tile_map);
  std::string pathFind(const int& start_x, const int& start_y, const int& finish_x, const int& finish_y);
  void route_planning();
  void print_map();
  ~Path_finder();
};

