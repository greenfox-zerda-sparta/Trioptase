#pragma once
#include "MapNode.hpp"
#include <vector>

using std::vector;

class LevelMap {
//private:
public:
  vector<vector<MapNode>> nodes;
public:
  LevelMap();
  ~LevelMap();
};

