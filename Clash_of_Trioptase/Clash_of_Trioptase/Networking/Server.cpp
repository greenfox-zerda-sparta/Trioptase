#include "Server.h"
#include <map>


Server::Server() {
}

void Server::init() {
  std::cout << "///////////////////////////////////////////////meg egy nagy adagf lofasz just for wths" << std::endl;
  set = SDLNet_AllocSocketSet(2);
  SDLNet_ResolveHost(&ip, NULL, 1234);
  server = SDLNet_TCP_Open(&ip);
  SDLNet_TCP_AddSocket(set, server);
  client = SDLNet_TCP_Accept(server);
  client_connected = wait_for_client();
}

void Server::send(json& _message) {
  if (!has_client) {
    std::cout << "no client has connected yet\n";
    return;
  }
  string text = json_to_string(_message);
  bool running = true;
  while (running) {
    if (SDLNet_TCP_Send(client, text.c_str(), text.length() + 1)) {
      running = false;
    }
  }
}

json Server::receive() {
  bool running = true;
  while (running) {
    if (SDLNet_CheckSockets(set, 1000)) {
      if (SDLNet_SocketReady(client)) {
        SDLNet_TCP_Recv(client, client_chars, 90000);
        recived_message_to_json();
        running = false;
      }
    }
  }
  return client_mess_json;
}

bool Server::wait_for_client() {
  int start = SDL_GetTicks();
  bool running = true;
  while (running) {
    std::cout << "client: " << client << std::endl;
    if (client || start - SDL_GetTicks() < 1000) {
      SDLNet_TCP_AddSocket(set, client);
      has_client = true;
      running = false;
      return  client ? true : false;
    }
    else {
      client = SDLNet_TCP_Accept(server);
    }
  }
  return false;
}

void Server::recived_message_to_json() {
  for (int i = 0; i < 90000; i++) {
    message_vector.push_back(client_chars[i]);
  }
  client_mess_json = json::from_msgpack(message_vector);
}


Server::~Server() {
  SDLNet_TCP_Close(client);
  SDLNet_TCP_Close(server);
  SDLNet_FreeSocketSet(set);
  SDLNet_Quit();
}
