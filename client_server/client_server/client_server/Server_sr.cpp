#include "Server_sr.hpp"

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
  while (1) {
    if (client) {
      SDLNet_TCP_AddSocket(set, client);
      break;
    }
    else {
      client = SDLNet_TCP_Accept(server);
    }
  }
}

void Server_sr::server_accept() {
  this->client = SDLNet_TCP_Accept(server);
  while (1) {
    if (client) {
      SDLNet_TCP_AddSocket(set, client);
      break;
    }
    else {
      this->client = SDLNet_TCP_Accept(server);
    }
  }
  return;
}

void Server_sr::server_chat() {
  while (1) {
    client = SDLNet_TCP_Accept(server);
    if (client) {
      SDLNet_TCP_AddSocket(set, client);
      while (1) {
        if (_kbhit() != 0) {
          getline(std::cin, server_mess);
          server_chars = server_mess.c_str();
          SDLNet_TCP_Send(client, server_chars, server_mess.length() + 1);
          if (server_mess == "exit" || server_mess == "quit") {
            break;
          }
        }
        int activeSockets = SDLNet_CheckSockets(set, 10);
        if (activeSockets != 0) {
          int gotMessage = SDLNet_SocketReady(client);
          if (gotMessage != 0) {
            SDLNet_TCP_Recv(client, client_chars, 100);
            client_mess = client_chars;
            if (client_mess == "exit" || client_mess == "quit") {
              break;
            }
            std::cout << client_mess << std::endl;
          }
        }
      }
      this->server_close();
    }
    if (server_mess == "exit" || server_mess == "quit") {
      break;
    }
  }
}

void Server_sr::server_send(std::string in_server_mess) {
  while (1) {
    server_chars = in_server_mess.c_str();
    SDLNet_TCP_Send(client, server_chars, in_server_mess.length() + 1);
    break;
  }
}

void Server_sr::server_client_open() {
  client = SDLNet_TCP_Accept(server);
}

std::string Server_sr::server_receive() {
  while (1) {
    this->activeSockets = SDLNet_CheckSockets(set, 10);
    if (activeSockets != 0) {
      this->gotMessage = SDLNet_SocketReady(client);
      if (this->gotMessage != 0) {
        SDLNet_TCP_Recv(client, client_chars, 100);
        client_mess = client_chars;
        break;
      }
    }
  }
  return client_mess;
}

void Server_sr::server_client_close() {
  SDLNet_TCP_Close(client);
}

void Server_sr::server_close() {
  SDLNet_TCP_Close(client);
  SDLNet_TCP_Close(server);
  SDLNet_FreeSocketSet(set);
}

void Server_sr::server_run() {

  this->server_init();
  this->server_chat();
  this->server_close();
}

Server_sr::~Server_sr() {
}
