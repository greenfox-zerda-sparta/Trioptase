#ifdef RELEASE

#include <iostream>
#include "Game_handler.hpp"

using namespace std;

int main(int argc, char* argv[]) {
  Game_handler my_game;
  my_game.run();
  return 0;
}

#endif