#include "Client.h"

Client::Client(string ip_address) {
  set_stat = true;
  this->ip_address = ip_address;
}

void Client::client_init() {
  SDLNet_Init();
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, ip_address.c_str(), 1234);
  this->client = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, client);
  this->activeSockets = SDLNet_CheckSockets(set, 10);
}

void Client::client_send(string client_mess) {
  bool running = true;
  while (running) {
    SDLNet_TCP_Send(client, client_mess.c_str(), client_mess.length() + 1);
    running = false;
  }
}

void Client::recived_message_to_json() {
  for (int i = 0; i < 90000; i++) {
    message_vector.push_back(server_chars[i]);
  }
  server_mess = json::from_msgpack(message_vector);
}

json Client::client_receive() {
  bool running = true;
  while (running) {
    this->activeSockets = SDLNet_CheckSockets(set, 10);
    if (this->activeSockets != 0) {
      gotMessage = SDLNet_SocketReady(client);
      if (gotMessage != 0) {
        SDLNet_TCP_Recv(client, server_chars, 90000);
        recived_message_to_json();
        running = false;
      }
    }
  }
  return server_mess;
}


void Client::client_close() {
  SDLNet_TCP_Close(client);
  SDLNet_FreeSocketSet(set);
}

Client::~Client() {
  SDLNet_Quit();
}
