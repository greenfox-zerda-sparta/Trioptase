#include "Broadcast.h"
#include <iostream>

using std::cout;
using std::endl;

const int WAIT = 5000;

int main(int argc, char* argv[]) {
  Broadcast ray("10.27.99.255", 1234, 1233);
  
  /*cout << "ip: " << ray.ip_address << endl;
  cout << "local port: " << ray.local_port << endl;
  cout << "remote port: " << ray.remote_port << endl;
  cout << "decimal ip(169567231): " << ray.server_ip.host << endl;
  cout << "decimal ip's port(1234): " << ray.server_ip.port << endl;*/

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
    int current_time = SDL_GetTicks();
    if (current_time - start > WAIT) {
      cout << "server mode start\n";
      ray.server_mode = true;
      running = false;
    }
  }
  ray.start_game();
  return 0;
}