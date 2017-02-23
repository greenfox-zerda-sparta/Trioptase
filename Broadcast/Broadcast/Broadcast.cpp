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
  string msg = std::to_string(my_ip.host);
  std::cout << msg << std::endl;
  memcpy(packet->data, msg.c_str(), msg.length());
  std::cout << packet->data << std::endl;
  packet->len = msg.length();
  SDLNet_UDP_Send(outSocket, -1, packet);
  std::cout << "broadcast" << std::endl;

}

int Broadcast::recieve() {
  if (SDLNet_UDP_Recv(inSocket, income)) {
    Uint8 msg = *income->data;
    string alma = std::to_string(msg);
    alma += "\0";
    communicate = new Client(alma);
  
  }
  return 0;
}

void Broadcast::start_game() {
  server_mode ? start_server_mode() : start_client_mode();
}

void Broadcast::start_server_mode() {
  communicate = new Server;
}

void Broadcast::resolve_IP() {
  my_ip.host = NULL;
  my_ip.port = 69;  
  SDLNet_ResolveHost(&my_ip, SDLNet_ResolveIP(&my_ip), 69);
  my_ip.host = SDL_Swap32(my_ip.host);
}

void Broadcast::start_broadcasting() {
  resolve_IP();
  while (1) {
    send();
  }
}

Broadcast::~Broadcast() {
  SDLNet_FreePacket(packet);
  SDLNet_Quit();
  delete communicate;
}
