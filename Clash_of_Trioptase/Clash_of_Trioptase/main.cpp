#ifdef RELEASE

#include <iostream>
#include "Game_handler.hpp"

int main(int argc, char* argv[]) {
  Game_handler my_game;
  my_game.initialization();
  my_game.run();
  my_game.deinitialization();
  return 0;
}

#endif