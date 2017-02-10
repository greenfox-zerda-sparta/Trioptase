#pragma once
#include "MapNode.hpp"
class Building :public MapNode {
public:
  Building(pair<int, int>);
  ~Building();
};

