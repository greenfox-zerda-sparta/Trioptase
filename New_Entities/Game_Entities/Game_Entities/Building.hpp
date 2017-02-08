#pragma once
#include "Game_entity.hpp"
class Building : public Game_entity {
public:
  Building();
  string to_json();
  ~Building();
};

