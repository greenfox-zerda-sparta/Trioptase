#include "MapNode.hpp"
#include <iostream>

MapNode::MapNode() {
  entity_img_path = "";
}

string MapNode::get_img_path() {
  return entity_img_path;
}

Game_entity* MapNode::get_entity() {
  return entity;
}

void MapNode::set_entity(Game_entity* _new_entity) {
  entity = _new_entity;
  entity_img_path = entity->IMG_PATH;
}

MapNode::~MapNode() {
}
