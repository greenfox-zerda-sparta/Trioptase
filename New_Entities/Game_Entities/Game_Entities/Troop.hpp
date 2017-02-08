#pragma once
#include "Game_entity.hpp"
class Troop : public Game_entity {
public:
  string to_json();
  Troop();
  int get_hp();
  void set_hp(int);
  int get_ap();
  void set_ap(int);
  int get_dp();
  void set_dp(int);
  int get_lvl();
  void lvl_up();
  int get_price();
  void set_price(int);
  ~Troop();
private:
  int health_point = 0;
  int attack_point = 0;
  int defense_point = 0;
  int level = 1;
  int price = 0;
};

