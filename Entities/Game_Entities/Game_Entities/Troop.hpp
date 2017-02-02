#pragma once
#include "MapNode.hpp"
#include "Game.hpp"

class Troop : public MapNode {
private:
  int path_length;
public:
  Troop(pair<int,int>);
  void move_troop();
  ~Troop();
};

