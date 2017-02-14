#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <WindowsX.h>
#include "json.hpp"

using json = nlohmann::json;

class Server_sr {
private:
  IPaddress ip;
  TCPsocket server;
  TCPsocket client;
  SDLNet_SocketSet set;
  int activeSockets;
  int gotMessage;

  bool set_stat;
  char client_chars[100];
  const char* server_chars;
  std::string client_mess;
  std::string server_mess;
public:
  Server_sr();
  void server_init();    
  void server_send(json _message);  
  std::string server_receive();  
  void server_close();
  ~Server_sr();
};