#include "Building.hpp"

Building::Building(pair<int, int> start_coords) {
  x_coord = start_coords.first;
  y_coord = start_coords.second;
  this->tile_image_path = "pic/building.png";
}

Building::~Building() {
}

pair<int, int> Building::getCordinates() {
  pair<int, int> coords = { x_coord , y_coord };
  return coords;
}