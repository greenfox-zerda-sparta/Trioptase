#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include "json.hpp"

using json = nlohmann::json;

class Client_cl {
private:
  IPaddress ip;
  TCPsocket client;
  SDLNet_SocketSet set;
  bool set_stat;
  int activeSockets;
  int gotMessage;
  //char server_chars[100];
  const char* client_chars;
  std::string client_mess;
  //std::string server_mess;
  //json server_chars;
  json* server_mess;

public:
  Client_cl();
  void client_init();
  void client_send(std::string);
  json client_receive();
  void client_close();
  ~Client_cl();
};