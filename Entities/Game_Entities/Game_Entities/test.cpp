#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "LevelMap.hpp"
#include "MapNode.hpp"
#include "Game.hpp"


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

TEST_CASE("Game class") {
  Game* my_game = Game::get_game_instance();
  REQUIRE(my_game->game_LevelMap.nodes.empty());
}
/*
TEST_CASE("checking map biuld in singleton's constructor") {
  REQUIRE(Game::get_game_instance()->tile_map[0][0] == 3);
}
*/
TEST_CASE("checking tile map size") {
  REQUIRE(Game::get_game_instance()->tile_map.size() == 30);
}