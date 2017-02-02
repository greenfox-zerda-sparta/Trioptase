#include "Troop.hpp"


Troop::Troop(pair<int, int> coordinates) {
  node_type = TROOP;
  x_coord = coordinates.first;
  y_coord = coordinates.second;
  this->tile_image_path = "pic/troop.png";
}

void Troop::move_troop() {
  Game* my_game = Game::get_game_instance();
  path_length = my_game->troop_path.size();
  if(path_length > 0) {
    x_coord = my_game->troop_path[path_length - 1].first;
    y_coord = my_game->troop_path[path_length - 1].second;
    my_game->troop_path.pop_back();
  }
}


Troop::~Troop() {
}
