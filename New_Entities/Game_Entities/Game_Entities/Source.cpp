#ifndef TEST
#include <iostream>
#include "Troop.hpp"
#include "Building.hpp"
#include "MapNode.hpp"
#include "Map.hpp"
#include <string>
#include <iterator>
#include <time.h>

using std::cout;
using std::endl;
using std::string;
using std::iterator;
using std::time;

int main() {
  time_t start_time;
  time(&start_time);
  cout << "start:" << start_time << endl;
  Map map;
  for (int i = 0; i < MAP_SIZE; i++) {
    for (int j = 0; j < MAP_SIZE; j++) {
      map.node_map[i][j]->set_entity(new Troop);
    }
  }
  cout << map.to_json() << endl;
  time_t end_time;
  time(&end_time);
  cout << "end:" << end_time << endl;
  cout << end_time - start_time << endl;
  return 0;

}

#endif // !TEST
