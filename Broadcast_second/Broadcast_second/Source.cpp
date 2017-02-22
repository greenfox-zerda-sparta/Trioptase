#include <SDL.h>
#include <SDL_net.h>
#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::for_each;
using std::stoi;

const char* MY_IP = "10.27.6.226";
const char* BROADCAST_IP = "10.27.6.255";
const char* MASK = "255.255.255.0";


bool ipStringToNumber(unsigned int byte3, unsigned int byte2, unsigned int byte1, unsigned int byte0, unsigned int* pIpAddr) {
  if ((byte3 < 256) && (byte2 < 256) && (byte1 < 256) && (byte0 < 256)) {
    *pIpAddr = (byte3 << 24) + (byte2 << 16) + (byte1 << 8) + byte0;
    return true;
  }
  return false;
}

int main(int argc, char* argv[]) {
  SDLNet_Init();
  IPaddress address;
  
  if (ipStringToNumber(10, 27, 6, 255, &address.host)) {
    cout << "address.host: " << address.host << endl;
  }
  address.port = 1234;
  cout << "address.port: " << address.port << endl;

  UDPsocket udp_socket = SDLNet_UDP_Open(address.port);
  cout << "udp_socket: " << udp_socket << endl;
  SDLNet_UDP_Bind(udp_socket, 1, &address);

  UDPpacket message;
  message.address.host = address.host;
  message.address.port = address.port;
  message.channel = 1;
  Uint8 alma = 'a';
  alma += '\0';
  message.data = &alma;
  message.len = 2;
  message.maxlen = 32;

  bool first = true;
  while (1) {
    std::cout << SDLNet_UDP_Send(udp_socket, message.channel, &message);
    if (first) {
      std::cout << "msg.add.host: " << message.address.host << std::endl;
      std::cout << "msg.add.port: " << message.address.port << std::endl;
      std::cout << "msg.channel: " << message.channel << std::endl;
      std::cout << "msg.data: " << message.data << std::endl;
      std::cout << "msg.len: " << message.len << std::endl;
      std::cout << "msg.max.len: " << message.maxlen << std::endl;
      std::cout << "msg.status: " << message.status << std::endl;
      first = false;
    }
  }

  SDLNet_UDP_Close(udp_socket);
  SDLNet_Quit();
}
