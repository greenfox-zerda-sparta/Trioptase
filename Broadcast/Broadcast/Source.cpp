#include "Broadcast.h"
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  Broadcast ray("255.255.255.255", 1234, 1233);

 
  return 0;
}