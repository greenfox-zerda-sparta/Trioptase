#include "Troop.hpp"



void Troop::move_troop() {
  Game* my_game = Game::get_game_instance();
  path_length = my_game->troop_path.size();
  if(path_length > 0) {
    x_coord = my_game->troop_path[path_length - 1].first;
    y_coord = my_game->troop_path[path_length - 1].second;
    my_game->troop_path.pop_back();
  }
}

pair<int, int> Troop::getCordinates() {
  pair<int, int> cords;
  cords.first = x_coord;
  cords.second = y_coord;
  return cords;
}

bool Troop::get_click_status() {
  return click_status;
}

void Troop::set_click_status() {
  click_status ? click_status = false : click_status = true;
}

Troop::Troop(pair<int,int> coordinates) {
  x_coord = coordinates.first;
  y_coord = coordinates.second;
  this->tile_image_path = "pic/troop.png";
}


Troop::~Troop()
{
}
