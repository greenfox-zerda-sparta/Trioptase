#include "Map.hpp"

Map::Map(int _map_size) {
  this->map_size = _map_size;
  this->my_map.resize(this->map_size);
  for (int i = 0; i < my_map.size(); i++) {
    my_map[i].resize(this->map_size, 0);
  }
}

int Map::get_my_map_data(int x, int y) {
  return my_map[y][x];
}

Map::~Map() {
}
