#pragma once
#include "Game_entity.hpp"
class Building : public Game_entity {
public:
  Building();
  json to_json();
  ~Building();
};

