#include "Server_sr.hpp"
#include <map>

std::string Server_sr::json_to_string(json& _message) {
  std::vector<uint8_t> temp_vec = json::to_msgpack(_message);
  std::string text;
  for (int i = 0; i < temp_vec.size(); i++) {
    text += temp_vec[i];
  }
  return text;
}

Server_sr::Server_sr() {
  set_stat = true;
}

void Server_sr::server_init() {
  SDL_Init(SDL_INIT_EVERYTHING);
  SDLNet_Init();
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, NULL, 1234);
  this->server = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, server);
  this->client = SDLNet_TCP_Accept(server);
  bool running = true;
  while (running) {
    if (client) {
      SDLNet_TCP_AddSocket(set, client);
      running = false;
    }
    else {
      client = SDLNet_TCP_Accept(server);
    }
  }
}

void Server_sr::server_send(json& _message) {          
  std::string text = json_to_string(_message);
  bool running = true;
  while (running) {
    SDLNet_TCP_Send(client, text.c_str(), text.length() + 1);
    running = false;
  }
}

std::string Server_sr::server_receive() {
  bool running = true;
  while (running) {
    this->activeSockets = SDLNet_CheckSockets(set, 10);
    if (activeSockets != 0) {
      this->gotMessage = SDLNet_SocketReady(client);
      if (this->gotMessage != 0) {
        SDLNet_TCP_Recv(client, client_chars, 100);
        client_mess = client_chars;
        running = false;
      }
    }
  }
  return client_mess;
}

void Server_sr::server_close() {
  SDLNet_TCP_Close(client);
  SDLNet_TCP_Close(server);
  SDLNet_FreeSocketSet(set);
}

Server_sr::~Server_sr() {
}
