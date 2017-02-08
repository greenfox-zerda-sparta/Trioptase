#ifdef TEST
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.h"
#include "Troop.hpp"

TEST_CASE("failing interface test") {
  class test_class : public JSON_Serial {
  public:
    test_class() {};
  };
  //test_class my_test_class;
  // commented line becouse it breaks compiling 
}

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

/*TEST_CASE("Game_entity class exists") {
  Game_entity my_game_entity;
}

TEST_CASE("Game_entity is a child of JSON_Serial") {
  Game_entity my_game_entity;
  REQUIRE(my_game_entity.to_json() == "");
}*/ //Game_entity is an abstract class 

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

#endif // TEST
