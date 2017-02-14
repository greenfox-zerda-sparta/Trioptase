#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_net.h>
#include <conio.h>
#include <string>
#include <cstring>
#include <WindowsX.h>

class Server_sr {
private:
  IPaddress ip;
  TCPsocket server;
  TCPsocket client;
  SDLNet_SocketSet set;
  int activeSockets;
  int gotMessage;

  bool set_stat;
  char client_chars[100];
  const char* server_chars;
  std::string client_mess;
  std::string server_mess;
public:
  Server_sr();
  void server_init();
  void server_accept();
  void server_chat();
  void server_send(std::string);
  void server_client_open();
  std::string server_receive();
  void server_client_close();
  void server_close();
  void server_run();
  ~Server_sr();
};