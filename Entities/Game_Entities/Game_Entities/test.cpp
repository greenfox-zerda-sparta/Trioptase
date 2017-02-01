#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "LevelMap.hpp"

TEST_CASE("create class") {
  LevelMap mymap;
}

TEST_CASE("LevelMap has vector") {
  LevelMap mymap;
  REQUIRE(mymap.nodes.size() == 0);
}

