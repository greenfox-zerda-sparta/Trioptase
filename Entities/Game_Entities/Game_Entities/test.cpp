#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "LevelMap.hpp"
#include "MapNode.hpp"

TEST_CASE("LevelMap class") {
  LevelMap mymap;
}

TEST_CASE("LevelMap has vector") {
  LevelMap mymap;
  REQUIRE(mymap.nodes.size() == 0);
}

TEST_CASE("MapNode class") {
  MapNode mynode;
}

TEST_CASE("Tyle type path") {
  MapNode mynode;
  REQUIRE(mynode.get_tile_image_path() == "");
}

TEST_CASE("MapNode constructor") {
  MapNode mynode("frutyi");
  REQUIRE(mynode.get_tile_image_path() == "frutyi");
}

