#pragma once
#include <SDL_net.h>
#include <string>
#include "Network.h"
#include "Server.h"
#include "Client.h"

using std::string;

class Broadcast {
public:
  Broadcast(const string& ip, int32_t remote, int32_t local);
  ~Broadcast();
  void start_broadcasting();
  void set_server();
  void set_client();
  void send();
  int recieve();
  void start_game();
  void start_server_mode();
  void start_client_mode() {};
  void resolve_IP();
public:
  bool server_mode;
  UDPsocket outSocket;
  UDPsocket inSocket;
  IPaddress server_ip;
  IPaddress my_ip;
  UDPpacket* packet;
  UDPpacket* income;
  const string ip_address;
  int32_t remote_port;
  int32_t local_port;
  Network* communicate = nullptr;
};

