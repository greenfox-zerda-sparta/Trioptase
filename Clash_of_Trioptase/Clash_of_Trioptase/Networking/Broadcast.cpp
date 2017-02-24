#include "Broadcast.h"
#include <math.h>

Broadcast::Broadcast(const string& ip, int32_t remote, int32_t local): ip_address(ip) {
  remote_port = remote;
  local_port = local;
  SDLNet_Init();
  server_mode = false;
  set_server();
  set_client();
  start_listening();
}

void Broadcast::start_listening() {
  int start_time = SDL_GetTicks();
  bool running = true;
  while (running) {
    if (recieve() || SDL_GetTicks() > start_time + WAIT) {
      running = false;
    }
  }
  start_game();
}

void Broadcast::send() {
  string msg = std::to_string(my_ip.host);
  memcpy(packet->data, msg.c_str(), msg.length());
  packet->len = msg.length();
  std::cout << "send packet's data" << packet->data << std::endl;
  SDLNet_UDP_Send(outSocket, -1, packet);
}

bool Broadcast::recieve() {
  if (SDLNet_UDP_Recv(inSocket, income)) {
    server_mode = false;
    return !server_mode;
  }
  server_mode = true;
  return !server_mode;
}

void Broadcast::start_game() {
  server_mode ? start_server_mode() : start_client_mode();
}

void Broadcast::start_server_mode() {
  communicate = new Server;
  std::cout << "server mode start" << std::endl;
  start_broadcasting();
}

void Broadcast::start_client_mode() {
  string ip_str;
  for (int i = 0; i < 9; i++) {
    ip_str += income->data[i];
  }
  communicate = new Client(ip_str);
}

void Broadcast::resolve_IP() {
  my_ip.host = NULL;
  my_ip.port = 69;  
  SDLNet_ResolveHost(&my_ip, SDLNet_ResolveIP(&my_ip), 69);
  my_ip.host = SDL_Swap32(my_ip.host);
}

void Broadcast::start_broadcasting() {
  resolve_IP();
  int start_time = SDL_GetTicks();
  while (SDL_GetTicks() - start_time < 10000) {
    send();
  }
}

Broadcast::~Broadcast() {
  SDLNet_FreePacket(packet);
  SDLNet_Quit();
  delete communicate;
}

void Broadcast::set_server() {
  outSocket = SDLNet_UDP_Open(local_port);
  SDLNet_ResolveHost(&server_ip, ip_address.c_str(), remote_port);
  packet = SDLNet_AllocPacket(512);
  packet->address.host = server_ip.host;
  packet->address.port = server_ip.port;
}

void Broadcast::set_client() {
  inSocket = SDLNet_UDP_Open(remote_port);
  income = SDLNet_AllocPacket(512);
}
