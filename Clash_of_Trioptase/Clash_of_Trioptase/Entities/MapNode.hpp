#pragma once
#include "Game_entity.hpp"

class MapNode {
public:
  MapNode();
  string get_img_path();
  Game_entity* get_entity();
  void set_entity(Game_entity*);
  ~MapNode();
private:
  string entity_img_path;
  Game_entity* entity = NULL;
};

