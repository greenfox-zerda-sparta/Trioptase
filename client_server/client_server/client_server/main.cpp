#ifndef TEST

#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include "Server_sr.hpp"

int main(int argc, char* argv[]) {
  Server_sr my_server;
  std::cout << "Server is waiting for client" << std::endl;
  my_server.server_init();
  std::cout << my_server.server_receive() << std::endl;
  my_server.server_close();

  return 0;
}

#endif // !TEST
