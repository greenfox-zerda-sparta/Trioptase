#ifndef TEST
#include <iostream>
#include "Troop.hpp"
#include "Building.hpp"
#include "MapNode.hpp"

using std::cout;
using std::endl;

int main() {
  cout << "DEBUG" << endl;
  Troop troop;
  Building haus;
  MapNode node;
  cout << node.get_img_path() << endl;
  node.set_entity(&haus);
  cout << node.get_img_path() << endl;

  return 0;
}

#endif // !TEST
