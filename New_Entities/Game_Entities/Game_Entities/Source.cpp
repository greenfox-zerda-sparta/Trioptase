#ifndef TEST
#include <iostream>
#include "Troop.hpp"
#include "Building.hpp"
#include "MapNode.hpp"
#include <string>
#include <iterator>

using std::cout;
using std::endl;
using std::string;
using std::iterator;

int main() {
  
  Troop soldier;

  json j = soldier.to_json();
  for (json::iterator it = j.begin(); it != j.end(); ++it) {
    cout << it.key() << " : " << *it << endl;
  }

  
  return 0;

}

#endif // !TEST
