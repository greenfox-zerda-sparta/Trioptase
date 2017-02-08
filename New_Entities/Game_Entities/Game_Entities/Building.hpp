#pragma once
#include "Game_entity.hpp"
class Building : public Game_entity {
public:
  Building();
  string to_json();
  int get_lvl();
  void set_lvl(int);

  int get_hp();
  void set_hp(int);  
  
  int get_price();
  void set_price(int);
  ~Building();
private:
  int level = 0;
  int health_point = 0;
  int price = 0;
};

