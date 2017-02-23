#include "Map.hpp"

Map::Map() {  
  if (this->node_map.size() != MAP_SIZE) {
    this->node_map.clear();
    this->init_map();
  }
}

void Map::init_map() {
  for (int i = 0; i < MAP_SIZE; i++) {
    vector<MapNode*> inner_vector;
    for (int j = 0; j < MAP_SIZE; j++) {
      inner_vector.push_back(new MapNode);
    }
    node_map.push_back(inner_vector);
  }
}

void Map::clear_map() {
  node_map.clear();
}

json Map::to_json() {
  int temp_ID;
  json temp_json;
  json temp_full_node;
  json to_return_j;
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      if (node_map[i][j]->get_entity() == NULL) {       
        temp_full_node = { "0", nullptr };
      }
      else {        
        temp_ID = node_map[i][j]->get_entity()->ID;
        temp_json = node_map[i][j]->get_entity()->to_json();
        temp_full_node = { std::to_string(temp_ID), temp_json };

      }
      to_return_j["Map"] += temp_full_node;
    } // end of second for loop
  } // end of first for loop
  return to_return_j;
} // end of to_json() method

Map::~Map() {
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      delete node_map[i][j];
      node_map[i][j] = NULL;
    }
  }
} // end of to_json() method