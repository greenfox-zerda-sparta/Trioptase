#pragma once
#include <SDL_net.h>
#include <string>
#include "Network.h"
#include "Server.h"
#include "Client.h"

using std::string;

const int WAIT = 2000;

class Broadcast {
public:
  Broadcast(const string& ip, int32_t remote, int32_t local);
  ~Broadcast();
private:
  void start_listening();//
  bool recieve(); //
  void start_game(); //
  void start_server_mode(); //
  void start_broadcasting();
  void resolve_IP(); //
  void send(); //
  void start_client_mode();//
public:
  void set_server();
  void set_client();
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

