#pragma once
#include "MapNode.hpp"
#include "Game.hpp"

class Troop : public MapNode {
private:
  int x_coord;
  int y_coord;
  int path_length;
  bool click_status = false;
public:
  Troop(pair<int,int>);
  void move_troop();
  pair<int, int> getCordinates();
  bool get_click_status();
  void set_click_status();
  ~Troop();
};

