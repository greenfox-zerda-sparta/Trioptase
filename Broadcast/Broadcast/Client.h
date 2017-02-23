#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <map>
#include <vector>
#include "json.hpp"
#include "Network.h"

using json = nlohmann::json;
using std::string;
using std::vector;

class Client: public Network {
private:
  IPaddress ip;
  TCPsocket client;
  SDLNet_SocketSet set;
  char server_chars[90000];
  const char* client_chars;
  json server_mess;
  vector<uint8_t> message_vector;
  void recived_message_to_json();
public:
  Client(string);
  string ip_address;
  void client_init(); 
  void send(json&); 
  json receive(); 
  ~Client(); 
};