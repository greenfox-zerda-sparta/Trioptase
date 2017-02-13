#pragma once
#include "Game_entity.hpp"
class Building : public Game_entity {
public:
  const int ID;
  Building();
  string to_json();
  ~Building();
};

