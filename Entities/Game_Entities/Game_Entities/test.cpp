#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.h"
#include "Game.hpp"
#include "Troop.hpp"
#include "Building.hpp"
#include "Field.hpp"

/*TEST_CASE("LevelMap class constructor") {
  LevelMap mymap;
}

TEST_CASE("LevelMap first has an empty vector") {
  LevelMap mymap;
  REQUIRE(mymap.nodes.size() == 0);
}*/ //we dont need this for the demo

TEST_CASE("MapNode class constuctor") {
  MapNode mynode;
}

TEST_CASE("MapNode class has an empty string as img_path at the beginning") {
  MapNode mynode;
  REQUIRE(mynode.get_tile_image_path() == "");
}

/*TEST_CASE("MapNode constructor gets a string") {
  MapNode mynode("frutyi");
  REQUIRE(mynode.get_tile_image_path() == "frutyi");
}*/ //ignored 'couse we change of concept

TEST_CASE("Game singleton class is pointing to the same instant") {
  Game* my_game = Game::get_game_instance();
  Game* other_game = Game::get_game_instance();
  REQUIRE_FALSE(my_game->nodes.empty());
  REQUIRE_FALSE(other_game->nodes.empty());
  MapNode alma;
  vector<MapNode> map_node_vector;
  map_node_vector.push_back(alma);
  my_game->nodes.push_back(map_node_vector);
  REQUIRE(my_game->nodes.size() == 31); // couse of the previous push_back 
  REQUIRE(other_game->nodes.size() == 31);
}

/*TEST_CASE("checking map biuld in singleton's constructor") {
  REQUIRE(Game::get_game_instance()->tile_map[0][0] == 3);
}*/

TEST_CASE("Game singleton class's  tile_map size is constant") {
  REQUIRE(Game::get_game_instance()->tile_map.size() == 30);
}

TEST_CASE("Troop class constructor need a pair of ints") {
  pair<int, int> alma = { 1, 2 };
  Troop ogre(alma);
  REQUIRE(ogre.get_cordinates().first == 1);
  REQUIRE(ogre.get_cordinates().second == 2);
  REQUIRE(ogre.get_tile_image_path() == "pic/troop.png");
}

TEST_CASE("Troop class move_troop method") {
  Game* my_game = Game::get_game_instance();
  pair<int, int> next_step = { 1, 1 };
  my_game->troop_path.push_back(next_step);

  pair<int, int> start_point = { 0, 0 };
  Troop legolas(start_point);
  REQUIRE(legolas.get_cordinates().first == 0);
  REQUIRE(legolas.get_cordinates().second == 0);
  legolas.move_troop();
  REQUIRE(legolas.get_cordinates().first == 1);
  REQUIRE(legolas.get_cordinates().second == 1);
}

TEST_CASE("Building class constructor") {
  pair<int, int> place = { 1,3 };
  Building house(place);
  REQUIRE(house.get_cordinates().first == 1);
  REQUIRE(house.get_cordinates().second == 3);
  REQUIRE(house.get_tile_image_path() == "pic/building.png");
}

TEST_CASE("Troop clicked status changing") {
  pair<int, int> pos = { 0, 0 };
  Troop ogre(pos);
  REQUIRE_FALSE(ogre.get_click_status());
  ogre.set_click_status();
  REQUIRE(ogre.get_click_status());
}

TEST_CASE("Building clicked status changing") {
  pair<int, int> pos = { 0, 0 };
  Building ogre(pos);
  REQUIRE_FALSE(ogre.get_click_status());
  ogre.set_click_status();
  REQUIRE(ogre.get_click_status());
}

TEST_CASE("Field class constructor") {
  Field empty;
  REQUIRE(empty.get_tile_image_path() == "pic/field.png");
}

TEST_CASE("Filling tile map from nodes") {
  Game* my_game = Game::get_game_instance();
  pair<int, int> coords = { 1, 1 };
  Building house(coords);
  my_game->nodes[10][10] = house;
  my_game->fill_tile_map();
  REQUIRE(my_game->tile_map[25][28] == 0);
  REQUIRE(my_game->tile_map[10][10] == 1);
}

TEST_CASE("path_map changes at \"Building\" in nodes") {
  Game* my_game = Game::get_game_instance();
  pair<int, int> position = { 10, 10 };
  Building haus(position);
  my_game->nodes[10][10] = haus;
  my_game->fill_path_map();
  REQUIRE(my_game->path_map[10][10] == 1);
  REQUIRE(my_game->path_map[19][26] == 0);
}

#endif // TEST