#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <map>
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
  char server_chars[90000];
  const char* client_chars;
  json server_mess;
  std::vector<uint8_t> message_vector;
  std::string client_mess;

  void recived_message_to_json();
public:
  Client_cl();
  void client_init();
  void client_send(std::string);
  json client_receive();
  void client_close();
  ~Client_cl();
};