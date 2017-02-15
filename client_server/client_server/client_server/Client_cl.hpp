#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <map>
#include <fstream>
#include "json.hpp"



using json = nlohmann::json;
using std::string;

class Client_cl {
private:
  IPaddress ip;
  TCPsocket client;
  SDLNet_SocketSet set;
  bool set_stat;
  int activeSockets;
  int gotMessage;
  char server_chars[21];
  const char* client_chars;
  std::string client_mess;
  //std::string server_mess;
  json server_mess;

public:
  Client_cl();
  void client_init();
  void client_send(std::string);
  json client_receive();
  //void from_char_to_json();
  void client_close();
  ~Client_cl();
};