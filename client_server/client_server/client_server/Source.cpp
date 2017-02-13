#ifndef TEST
#include "ServerSocket.hpp"

int main(int argc, char *argv[]) {
  SDLNet_Init();
  ServerSocket* ss;
  ss = new ServerSocket(1234, 16, 5);
  int activeClient = -1;
  do {
    ss->checkForConnections();
    do {
      activeClient = ss->checkForActivity();
      if (activeClient != -1) {
        ss->dealWithActivity(activeClient);
      }
    } while (activeClient != -1);
  } while (ss->getShutdownStatus() == false);
  SDLNet_Quit();
  return 0;
}

#endif // !TEST
