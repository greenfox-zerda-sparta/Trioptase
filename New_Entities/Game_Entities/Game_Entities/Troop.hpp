#pragma once
#include "Game_entity.hpp"
class Troop : public Game_entity {
public:
  const int ID;
  string to_json();
  Troop();
  ~Troop();
private:
  int health_point = 0;
  int attack_point = 0;
  int defense_point = 0;
  int level = 1;
  int price = 0;
};

