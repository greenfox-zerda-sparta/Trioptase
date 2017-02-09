#pragma once 
#include "MapNode.hpp"
#include <vector>

using std::vector;

const int MAP_SIZE = 30;

class Map {
private:

public:
  Map();
  vector<vector<MapNode*>> node_map;
  ~Map();
};

