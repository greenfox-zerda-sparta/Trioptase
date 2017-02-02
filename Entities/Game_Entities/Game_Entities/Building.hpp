#pragma once
#include "MapNode.hpp"
class Building :public MapNode {
private:
  int x_coord;
  int y_coord;
public:
  Building(pair<int, int>);
  pair<int, int> getCordinates();
  ~Building();
};

