#include "Client.h"

Client::Client(string ip_address) {
  this->ip_address = ip_address;
}

void Client::client_init() {
  SDLNet_Init();
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, ip_address.c_str(), 1234);
  client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, client);
  /*activeSockets = */SDLNet_CheckSockets(set, 10);
}


void Client::send(json& _message) {
  string text = json_to_string(_message);
  bool running = true;
  while (running) {
    if (SDLNet_TCP_Send(client, text.c_str(), text.length() + 1)) {
      running = false;
    }
  }
}

void Client::recived_message_to_json() {
  for (int i = 0; i < 90000; i++) {
    message_vector.push_back(server_chars[i]);
  }
  server_mess = json::from_msgpack(message_vector);
}

json Client::receive() {
  bool running = true;
  while (running) {
    if (SDLNet_CheckSockets(set, 10)) {
      if (SDLNet_SocketReady(client)) {
        SDLNet_TCP_Recv(client, server_chars, 90000);
        recived_message_to_json();
        running = false;
      }
    }
  }
  return server_mess;
}


Client::~Client() {
  SDLNet_TCP_Close(client);
  SDLNet_FreeSocketSet(set);
  SDLNet_Quit();
}
