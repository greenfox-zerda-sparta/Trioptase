#define TEST
#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "LevelMap.hpp"
#include "Game.hpp"
#include "Troop.hpp"
#include "Building.hpp"



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

/*TEST_CASE("MapNode constructor") {
  MapNode mynode("frutyi");
  REQUIRE(mynode.get_tile_image_path() == "frutyi");
}*/

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

TEST_CASE("troop machen") {
  pair<int, int> alma = { 1, 2 };
  Troop ogre(alma);
  REQUIRE(ogre.getCordinates().first == 1);
  REQUIRE(ogre.getCordinates().second == 2);
  REQUIRE(ogre.get_tile_image_path() == "pic/troop.png");
}

TEST_CASE("troop movement") {
  Game* my_game = Game::get_game_instance();
  pair<int, int> next_step = { 1, 1 };
  my_game->troop_path.push_back(next_step);

  pair<int, int> start_point = { 0, 0 };
  Troop legolas(start_point);
  REQUIRE(legolas.getCordinates().first == 0);
  REQUIRE(legolas.getCordinates().second == 0);
  legolas.move_troop();
  REQUIRE(legolas.getCordinates().first == 1);
  REQUIRE(legolas.getCordinates().second == 1);
}

TEST_CASE("building class constructor") {
  pair<int, int> place = { 1,3 };
  Building house(place);
  REQUIRE(house.getCordinates().first == 1);
  REQUIRE(house.getCordinates().second == 3);
  REQUIRE(house.get_tile_image_path() == "pic/building.png");
}

TEST_CASE("troop clicked status changing") {
  pair<int, int> pos = { 0, 0 };
  Troop ogre(pos);
  REQUIRE_FALSE(ogre.get_click_status());
  ogre.set_click_status();
  REQUIRE(ogre.get_click_status());
}

#endif // TEST