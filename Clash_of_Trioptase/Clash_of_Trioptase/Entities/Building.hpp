#pragma once
#include "Game_entity.hpp"

class Building : public Game_entity {
public:
  Building();
  virtual json to_json();
  ~Building();
};