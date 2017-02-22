#pragma once
#include "JSON_Serial.hpp"
#include <iostream>
static int BASE_ID = 0;

class Game_entity : public JSON_Serial {
protected:
  int health_point = 0;
  int attack_point = 0;
  int defense_point = 0;
  int level = 1;
  int price = 0;

public:
  Game_entity();
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
  const int ID = 0;
  string IMG_PATH;
};

