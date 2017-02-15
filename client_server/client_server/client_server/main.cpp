#ifndef TEST

#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <fstream>
#include "Server_sr.hpp"
#include "Client_cl.hpp"
#include "minijson_writer.hpp"

using std::string;

json file_to_json_entire(string filename) {
  std::ifstream my_file;
  json content;
  my_file.open(filename.c_str());
  my_file >> content;
  return content;
}

int main(int argc, char* argv[]) {

  //Server_sr my_server;
  //json jani = { { "hero", "Buzz Lightyear" } };  
  //std::cout << "Server is waiting for client" << std::endl;
  //my_server.server_init();  
  //my_server.server_send(jani);
  //my_server.server_close();

  Client_cl my_client;
  my_client.client_init();
 // my_client.client_send("cicca");
  std::cout << my_client.client_receive() << std::endl;
  my_client.client_close();

  return 0;
}

#endif // !TEST
