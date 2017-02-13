#pragma once
#include "Game_entity.hpp"
class Building : public Game_entity {
public:
  const int ID;
  Building();
  //json to_json();
  ~Building();
};

