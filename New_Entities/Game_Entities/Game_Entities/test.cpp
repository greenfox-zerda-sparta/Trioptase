#ifdef TEST
#define CATCH_CONFIG_MAIN

#include <iostream>
#include "catch.h"
#include "Troop.hpp"
#include "Building.hpp"
#include "MapNode.hpp"
#include "Map.hpp"
//------------------------------------------------------------------

TEST_CASE("failing interface test") {
  class test_class : public JSON_Serial {
  public:
    test_class() {};
  };
  //test_class my_test_class;
  // commented line becouse it breaks compiling 
}
//------------------------------------------------------------------
TEST_CASE("JSON_Serial is an interface") {
  class test_class : public JSON_Serial {
  public:
    test_class() {};
    string to_json() {
      return "";
    }
  };
  test_class my_test_class;
  REQUIRE(my_test_class.to_json() == "");
}
//------------------------------------------------------------------
/*TEST_CASE("Game_entity class exists") {
  Game_entity my_game_entity;
}

TEST_CASE("Game_entity is a child of JSON_Serial") {
  Game_entity my_game_entity;
  REQUIRE(my_game_entity.to_json() == "");
}*/ //Game_entity is an abstract class 
//-------------------------------------------------------------------
TEST_CASE("Troop class inherits from JSON_Serial") {
  Troop soldier;
}

TEST_CASE("Troop class to_json() method returns a string") {
  Troop soldier;
  REQUIRE(soldier.to_json() == "");
}

TEST_CASE("Troop inherits from Game_entity") {
  Troop soldier;
  Game_entity* ge_pointer;
  ge_pointer = &soldier;
}

TEST_CASE("Troop has private varieble int HP with getter") {
  Troop soldier;
  REQUIRE(soldier.get_hp() == 0);
}

TEST_CASE("Troop has private varieble int HP with setter") {
  Troop soldier;
  REQUIRE(soldier.get_hp() == 0);
  soldier.set_hp(5);
  REQUIRE(soldier.get_hp() == 5);
}

TEST_CASE("Troop has private varieble int AP with getter") {
  Troop soldier;
  REQUIRE(soldier.get_ap() == 0);
}

TEST_CASE("Troop has private varieble int AP with setter") {
  Troop soldier;
  REQUIRE(soldier.get_ap() == 0);
  soldier.set_ap(5);
  REQUIRE(soldier.get_ap() == 5);
}

TEST_CASE("Troop has private varieble int DP with getter") {
  Troop soldier;
  REQUIRE(soldier.get_dp() == 0);
}

TEST_CASE("Troop has private varieble int DP with setter") {
  Troop soldier;
  REQUIRE(soldier.get_dp() == 0);
  soldier.set_dp(5);
  REQUIRE(soldier.get_dp() == 5);
}

TEST_CASE("Troop has level default (1),  with getter") {
  Troop soldier;
  REQUIRE(soldier.get_lvl() == 1);
}

TEST_CASE("Troop has a level up method") {
  Troop soldier;
  REQUIRE(soldier.get_lvl() == 1);
  soldier.lvl_up();
  REQUIRE(soldier.get_lvl() == 2);
}

TEST_CASE("Troop has price with getter, setter") {
  Troop tropa;
  REQUIRE(tropa.get_price() == 0);
  tropa.set_price(10);
  REQUIRE(tropa.get_price() == 10);
}

TEST_CASE("every Troop has uniqe id") {
  Troop soldier;
  Troop ogre;
  REQUIRE(ogre.ID == soldier.ID + 1);
}
//------------------------------------------------------------------
TEST_CASE("Building class inherits from JSON_Serial") {
  Building haus;
}

TEST_CASE("Building to_json method return string") {
  Building haus;
  REQUIRE(haus.to_json() == "");
}

TEST_CASE("Building has HP, lvl, price") {
  Building haus;
  REQUIRE(haus.get_hp() == 0);
  haus.set_hp(10);
  REQUIRE(haus.get_hp() == 10);
  REQUIRE(haus.get_price() == 0);
  haus.set_price(10);
  REQUIRE(haus.get_price() == 10);
  REQUIRE(haus.get_lvl() == 0);
  haus.set_lvl(10);
  REQUIRE(haus.get_lvl() == 10);
}

TEST_CASE("every Building has uniqe id") {
  Building haus;
  Building burg;
  REQUIRE(burg.ID == haus.ID + 1);
}
//------------------------------------------------------------------
//------------------------------------------------------------------
TEST_CASE("MapNode class") {
  MapNode node;
}

TEST_CASE("MapNode class has a pointer to a Gameplay_entity with a setter/ getter") {
  MapNode node;
  Building haus;
  node.set_entity(&haus);
  REQUIRE(node.get_entity()->to_json() == "");
}

TEST_CASE("MapNode has a string member entity_img_path with getter") {
  MapNode node;
  REQUIRE(node.get_img_path() == "pic/field.png");
}

TEST_CASE("MapNode set_entity() method changes entity_img_path to entity's img_path") {
  Troop soldier;
  Building hause;
  MapNode node;
  REQUIRE(node.get_img_path() == "pic/field.png");
  node.set_entity(&hause);
  REQUIRE(node.get_img_path() == "pic/building.png");
  node.set_entity(&soldier);
  REQUIRE(node.get_img_path() == "pic/troop.png");
}
//------------------------------------------------------------------
TEST_CASE("Map class") {
  Map map;
}

TEST_CASE("Map class has a vector filled with empty nodes") {
  Map map;
  REQUIRE(map.node_map.size() == MAP_SIZE);
  REQUIRE(map.node_map[2].size()== MAP_SIZE);
  REQUIRE(map.node_map[3][27]->get_img_path() == "pic/field.png");
}

#endif // TEST
