#pragma once
#include "Network.h"

using std::string;
using std::vector;

class Server: public Network {
private:
  SDLNet_SocketSet set;
  IPaddress ip;
  TCPsocket server;
  TCPsocket client;
  char client_chars[90000];
  vector<uint8_t> message_vector;
  json client_mess_json;
  bool has_client = false;
public:
  Server(); 
  void server_init(); 
  void send(json& _message); 
  json receive();
  ~Server();
private:
  void recived_message_to_json();
};