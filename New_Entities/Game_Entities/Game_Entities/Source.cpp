#ifndef TEST
#include <iostream>
#include "Troop.hpp"
#include "Building.hpp"
#include "MapNode.hpp"

using std::cout;
using std::endl;

int main() {
  //cout << "DEBUG" 
  Troop troop;
  Troop troop2;
  cout << troop2.ID << endl;
  cout << troop.ID << endl;
  Game_entity ent;
  cout << ent.ID;
  return 0;
}

#endif // !TEST
