#pragma once
#include "MapNode.hpp"
#include "Singleton.hpp"

class Troop : public MapNode {
private:
  int path_length;
public:
  Troop(pair<int,int>);
  void move_troop();
  void smooth_move_troop();
  void route_smoother();
  int get_path_size();
  ~Troop();
};

