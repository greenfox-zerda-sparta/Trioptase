#pragma once
#include "Game_entity.hpp"
class Troop : public Game_entity {
public:
  string to_json();
  Troop();
  ~Troop();
};

