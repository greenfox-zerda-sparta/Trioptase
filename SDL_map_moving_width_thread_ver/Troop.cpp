#include "Troop.hpp"

Troop::Troop(pair<int, int> coordinates) {
  node_type = TROOP;
  x_coord = coordinates.first;
  y_coord = coordinates.second;
  s_coord_x = float(coordinates.first);
  s_coord_y = float(coordinates.second);
  this->tile_image_path = "pic/troop.png";
}

void Troop::move_troop() {
  Singleton* my_game = Singleton::getInstance();
  path_length = my_game->route.size();
  if(path_length > 0) {
    x_coord = my_game->route[path_length - 1].first;
    y_coord = my_game->route[path_length - 1].second;
    my_game->route.pop_back();
  }
}

void Troop::smooth_move_troop() {
  Singleton* my_game = Singleton::getInstance();
  path_length = my_game->smooth_route.size();
 // std::cout << "size= " << my_game->smooth_route.size() << std::endl;
  if (path_length > 0) {
    s_coord_x = float(my_game->smooth_route[path_length - 1].first);
    s_coord_y = float(my_game->smooth_route[path_length - 1].second);
    my_game->smooth_route.pop_back();
    //std::cout << s_coord_x << std::endl;
    //std::cout << s_coord_y << std::endl;
  }
}

void Troop::route_smoother() {
  pair<float, float> temp;
  Singleton* my_game = Singleton::getInstance();
  path_length = my_game->route.size();
  float f_smoother = 1.2;
    for (int j = 0; j < path_length; j++) { 
      
      f_smoother = 1.2;

      for (int i = 0; i < 5; i++) {
        f_smoother -= 0.2;
        temp.first = (my_game->route[j].first) + f_smoother;
        temp.second = (my_game->route[j].second) + f_smoother;
        my_game->smooth_route.push_back(temp);        
      }
      my_game->route.pop_back();
    }
    //std::reverse(my_game->smooth_route.begin(), my_game->smooth_route.end());
}
int Troop::get_path_size() {
  return this->path_length;
}
  //



Troop::~Troop() {
}
