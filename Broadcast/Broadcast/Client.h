#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <map>
#include <vector>
#include "json.hpp"

using json = nlohmann::json;
using std::string;
using std::vector;

class Client {
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
  vector<uint8_t> message_vector;
  string client_mess;
  void recived_message_to_json();
public:
  Client(string);
  string ip_address;
  void client_init();
  void client_send(string);
  json client_receive();
  void client_close();
  ~Client();
};