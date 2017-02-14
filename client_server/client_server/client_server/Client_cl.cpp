#include "Client_cl.hpp"

Client_cl::Client_cl() {
  set_stat = true;
}

void Client_cl::client_init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, "10.27.6.25", 1234); //192.168.0.7  127.0.0.1
  this->client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, client);
  this->activeSockets = SDLNet_CheckSockets(set, 10);
}


void Client_cl::client_send(std::string client_mess) {
  bool running = true;
  while (running) {
    client_chars = client_mess.c_str();
    SDLNet_TCP_Send(client, client_chars, client_mess.length() + 1);
    running = false;
  }
}
struct trap {
  json jackson;
  int j;
};

std::map<int, int> Client_cl::client_receive() {
  bool running = true;
  trap halfej;
  while (running) {
    this->activeSockets = SDLNet_CheckSockets(set, 10);
    if (this->activeSockets != 0) {
      gotMessage = SDLNet_SocketReady(client);
      if (gotMessage != 0) {  
        SDLNet_TCP_Recv(client, &server_mess, 1000);
        std::cout << "size: " <<server_mess.size();
        running = false;
      }
    }
  }
  return server_mess;
}

void Client_cl::client_close() {
  SDLNet_TCP_Close(client);
  SDLNet_FreeSocketSet(set);
  SDL_Quit();
}

Client_cl::~Client_cl() {
}
