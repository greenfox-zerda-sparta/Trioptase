#ifndef TEST

#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include "Server_sr.hpp"
#include "Client_cl.hpp"

int main(int argc, char* argv[]) {
  //Server_sr my_server;
  //std::cout << "Server is waiting for client" << std::endl;
  //my_server.server_init();
  ////std::cout << my_server.server_receive() << std::endl;  
  ////json jani = { {"hero", "Buzz Lightyer"}, {"numba", 5000} };
  //my_server.server_send({ { "hero", "Buzz Lightyer" },{ "numba", 5000 } });
  //my_server.server_close();
  Client_cl my_client;
  my_client.client_init();
 // my_client.client_send("cicca");
  std::cout << my_client.client_receive() << std::endl;
  my_client.client_close();


  return 0;
}

#endif // !TEST
