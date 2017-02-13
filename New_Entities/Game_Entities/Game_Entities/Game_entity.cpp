#include "Game_entity.hpp"

Game_entity::Game_entity() {

}

json Game_entity::to_json() {
  json j = {
    { "health", health_point },
    { "attack", attack_point },
    { "defense", defense_point },
    { "level", level },
    { "price", price }
  };
  return j;
}

void Game_entity::set_hp(int _new_hp) {
  health_point = _new_hp;
}

int Game_entity::get_hp() {
  return health_point;
}

void Game_entity::set_ap(int _new_ap) {
  attack_point = _new_ap;
}

int Game_entity::get_ap() {
  return attack_point;
}

void Game_entity::set_dp(int _new_dp) {
  defense_point = _new_dp;
}

int Game_entity::get_lvl() {
  return level;
}

void Game_entity::lvl_up() {
  level++;
}

int Game_entity::get_price() {
  return price;
}

void Game_entity::set_price(int _price) {
  price = _price;
}

int Game_entity::get_dp() {
  return defense_point;
}