#include "Broadcast.h"
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

using std::cout;
using std::endl;

const int WAIT = 5000;

int main(int argc, char* argv[]) {
  Broadcast ray("255.255.255.255", 1234, 1233);

  ray.set_client();
  bool running = true;
  int start = SDL_GetTicks();
  while (running) {
    int a = ray.recieve();
    if (a) {
      cout << ray.income->data << endl;
      cout << "client mode start\n";
      ray.server_mode = false;
      running = false;
    }
    if (SDL_GetTicks() - start > WAIT) {
      cout << "server mode start\n";
      ray.server_mode = true;
      running = false;
    }
  }
  json json = { "alma", 5 };
  ray.start_game();
  ray.communicate->send(json);
  return 0;
}