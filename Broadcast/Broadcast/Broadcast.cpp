#include "Broadcast.h"

Broadcast::Broadcast(const string& ip, int32_t remote, int32_t local): ip_address(ip) {
  this->remote_port = remote;
  this->local_port = local;
  SDLNet_Init();
  server_mode = false;
}

void Broadcast::set_server() {
  outSocket = SDLNet_UDP_Open(local_port);
  SDLNet_ResolveHost(&this->server_ip, ip_address.c_str(), remote_port);
  packet = SDLNet_AllocPacket(512);
  packet->address.host = server_ip.host;
  packet->address.port = server_ip.port;
}

void Broadcast::set_client() {
  inSocket = SDLNet_UDP_Open(remote_port);
  income = SDLNet_AllocPacket(512);
}

void Broadcast::send() {
  string msg = "ClashOfSparta";
  memcpy(packet->data, msg.c_str(), msg.length());
  packet->len = msg.length();
  SDLNet_UDP_Send(outSocket, -1, packet);
}

int Broadcast::recieve() {
  return SDLNet_UDP_Recv(inSocket, income);
}

void Broadcast::start_game() {
  server_mode ? start_server_mode() : start_client_mode();
}

Broadcast::~Broadcast() {
  SDLNet_FreePacket(packet);
  SDLNet_Quit();
}
