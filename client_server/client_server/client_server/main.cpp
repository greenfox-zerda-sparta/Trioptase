#ifndef TEST

#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include "Server_sr.hpp"
#include "Client_cl.hpp"
#include "minijson_writer.hpp"

int main(int argc, char* argv[]) {

  Server_sr my_server;
  json jani = { { "hero", "Buzz Lightyear" } };
  jani.to_msgpack;
  std::cout << jani << std::endl;
  std::cout << sizeof(jani) << std::endl;
  std::vector<uint8_t> danika = json::to_msgpack(jani);
  std::cout << danika.size() << std::endl;
  
  char text[21];
  for (int i = 0; i < danika.size(); i++) {
    text[i] = danika[i];
  }

  for (int i = 0; i < danika.size(); i++) {
    std::cout << text[i];
  }
  std::cout << std::endl;

  std::vector<uint8_t> ferike;

  for (int i = 0; i < danika.size(); i++) {
    ferike.push_back(text[i]);
  }

  for (int i = 0; i < danika.size(); i++) {
    std::cout << ferike[i];
  }


  json jackson = json::from_msgpack(ferike);

  std::cout << std::endl << "Jackson Five's hero is = " << jackson["hero"] << std::endl;

  std::cout << std::endl;
  //std::cout << jani.to_msgpack << std::endl;
  std::cout << "Server is waiting for client" << std::endl;
  my_server.server_init();  
  my_server.server_send(jani);
  my_server.server_close();

 // Client_cl my_client;
 // my_client.client_init();
 //// my_client.client_send("cicca");
 // std::cout << my_client.client_receive() << std::endl;
 // my_client.client_close();


  return 0;
}

#endif // !TEST
