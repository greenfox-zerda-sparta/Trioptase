#ifndef TEST
#include <iostream>
#include "Troop.hpp"

using std::cout;
using std::endl;

int main() {
  cout << "DEBUG" << endl;
  Troop troop;
  cout << troop.ID << endl;
  Troop ogre;
  cout << ogre.ID << endl;

  return 0;
}

#endif // !TEST
