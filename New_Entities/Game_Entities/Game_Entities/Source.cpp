#ifndef TEST
#include <iostream>
#include "Troop.hpp"
#include "Building.hpp"
#include <string>
#include <iterator>
#include <time.h>
#include "Game.hpp"

using std::cout;
using std::endl;
using std::string;
using std::iterator;
using std::time;

int main() {
  
  Game* my_game = Game::get_game_instance();
  my_game->write_json_to_file(my_game->map->to_json());
  my_game->from_json(my_game->map->to_json());
  return 0;
}

#endif // !TEST
