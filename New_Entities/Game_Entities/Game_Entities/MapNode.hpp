#pragma once
#include "Game_entity.hpp"

class MapNode {
public:
  MapNode();
  Game_entity* entity = NULL;
  ~MapNode();
};

