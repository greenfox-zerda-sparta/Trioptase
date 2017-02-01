#include "MapNode.hpp"



string MapNode::get_tile_image_path() {
  return tile_image_path;
}

MapNode::MapNode()
{
}

MapNode::MapNode(string tile_path) {
  tile_image_path = tile_path;
}


MapNode::~MapNode()
{
}
