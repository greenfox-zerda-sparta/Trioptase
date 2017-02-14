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

json Map::to_json() {
  int temp_ID;
  json temp_json;
  json temp_full_node;
  json to_return_j;
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      temp_ID = node_map[i][j]->get_entity()->ID;
      temp_json = node_map[i][j]->get_entity()->to_json();
      temp_full_node = {std::to_string(temp_ID), temp_json};
      to_return_j["Map"] += temp_full_node;
    }
  }

  return to_return_j;
}




Map::~Map() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      delete node_map[i][j];
      node_map[i][j] = NULL;
    }
  }
}
