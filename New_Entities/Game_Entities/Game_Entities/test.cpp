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

#endif // TEST
