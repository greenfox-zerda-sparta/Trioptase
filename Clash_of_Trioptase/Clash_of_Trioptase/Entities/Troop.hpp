#pragma once
#include "Game_entity.hpp"
class Troop : public Game_entity {
public:
  json to_json();
  Troop();
  ~Troop();
private:
};

