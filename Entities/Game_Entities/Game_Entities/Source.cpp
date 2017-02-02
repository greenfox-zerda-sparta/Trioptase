//#define RELEASE

#ifdef RELEASE

#include <iostream>
#include "Game.hpp"

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  Game* my_game = Game::get_game_instance();
  
  return 0;
}


#endif // RELEASE
