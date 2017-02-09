#include "Building.hpp"

static int BASE_ID = 0;

Building::Building(): ID(++BASE_ID) {
}

string Building::to_json() {
  return "";
}

int Building::get_lvl() {
  return level;
}

void Building::set_lvl(int _lvl) {
  level = _lvl;
}

int Building::get_hp() {
  return health_point;
}

void Building::set_hp(int _hp) {
  health_point = _hp;
}

int Building::get_price() {
  return price;
}

void Building::set_price(int _price) {
  this->price = _price;
}


Building::~Building()
{
}
