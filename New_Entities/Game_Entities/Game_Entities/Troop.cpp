#include "Troop.hpp"

string Troop::to_json() {
  return "";
}

Troop::Troop() {
  health_point = 0;
  attack_point = 0;
  defense_point = 0;
}

void Troop::set_hp(int _new_hp) {
  health_point = _new_hp;
}

int Troop::get_hp() {
  return health_point;
}

void Troop::set_ap(int _new_ap) {
  attack_point = _new_ap;
}

int Troop::get_ap() {
  return attack_point;
}

void Troop::set_dp(int _new_dp) {
  defense_point = _new_dp;
}

int Troop::get_lvl() {
  return level;
}

void Troop::lvl_up() {
  level++;
}

int Troop::get_dp() {
  return defense_point;
}


Troop::~Troop() {
}
