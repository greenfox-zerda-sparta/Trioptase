#include "Broadcast.h"
#include <iostream>
#include "json.hpp"
#include "Client.h"

using json = nlohmann::json;

using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  //Broadcast ray("255.255.255.255", 1234, 1233);
  Client client("10.27.99.23");
  client.client_init();
 
  return 0;
}