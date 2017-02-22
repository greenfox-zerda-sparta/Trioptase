#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <WindowsX.h>
#include "json.hpp"
#include <vector>

using json = nlohmann::json;
using std::string;
using std::vector;

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
  string client_mess;
  string server_mess;
public:
  Server_sr();
  void server_init();    
  void server_send(json& _message);
  string server_receive();  
  void server_close();  
  ~Server_sr();
private:
  string json_to_string(json& _message);

};