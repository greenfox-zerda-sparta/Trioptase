#ifdef TEST
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.h"
#include "JSON_Serial.h"
#include "Game_entity.hpp"

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

TEST_CASE("Game_entity class exists") {
  Game_entity my_game_entity;
}

TEST_CASE("Is Game_entity child of JSON_Serial?") {
  Game_entity my_game_entity;
  REQUIRE(my_game_entity.to_json() == "");
}


#endif // TEST
