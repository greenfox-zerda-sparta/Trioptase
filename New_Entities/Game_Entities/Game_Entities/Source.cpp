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
  Troop troop;
  my_game->map->node_map[1][1]->set_entity(&troop);
  json my_json = my_game->map->to_json();
  cout << my_json << endl;
  cout << my_game->update_map_from_json(my_game->map->to_json()) << endl;

  return 0;
}

#endif // !TEST
