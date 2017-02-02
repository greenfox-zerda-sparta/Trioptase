#pragma once
#include "MapNode.hpp"
#include "Game.hpp"

using std::pair;

class Troop : public MapNode {
private:
  int x_coord;
  int y_coord;
  int path_length;
public:
  Troop(pair<int,int>);
  void move_troop();
  pair<int, int> getCordinates();
  ~Troop();
};

