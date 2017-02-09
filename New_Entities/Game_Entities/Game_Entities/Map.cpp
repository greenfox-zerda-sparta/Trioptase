#include "Map.hpp"



Map::Map() {
  for (int i = 0; i < MAP_SIZE; i++) {
    vector<MapNode*> inner_vector;
    for (int j = 0; j < MAP_SIZE; j++) {
      inner_vector.push_back(new MapNode);
    }
    node_map.push_back(inner_vector);
  }
}


Map::~Map() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      delete node_map[i][j];
      node_map[i][j] = NULL;
    }
  }
}
