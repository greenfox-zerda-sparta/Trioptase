#include <iostream>
#include <SDL.h>
#include <SDL_net.h>

int main(int argc, char* argv[]) {
  SDLNet_Init();
  UDPsocket udp_socket = SDLNet_UDP_Open(1234);

  bool runnung = true;
  UDPpacket message = *SDLNet_AllocPacket(1024);
  while (runnung) {
    //::cout << message.status;
    int a = SDLNet_UDP_Recv(udp_socket, &message);
    if (a) {
      std::cout << message.data << std::endl;
      runnung = false;
    }
  }
  SDLNet_FreePacket(&message);
  SDLNet_UDP_Close(udp_socket);
  SDLNet_Quit();
  return 0;
}
  