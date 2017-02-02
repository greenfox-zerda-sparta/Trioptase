#pragma once
#include "MapNode.hpp"
#include "Game.hpp"

class Troop : public MapNode {
private:
  int x_coord;
  int y_coord;
  int path_length;
public:
  Troop(pair<int,int>);
  void move_troop();
  pair<int, int> get_cordinates();
  ~Troop();
};

