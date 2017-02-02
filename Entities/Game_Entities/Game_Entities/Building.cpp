#include "Building.hpp"

Building::Building(pair<int, int> start_coords) {
  node_type = BUILDING;
  x_coord = start_coords.first;
  y_coord = start_coords.second;
  this->tile_image_path = "pic/building.png";
}

Building::~Building() {
}
