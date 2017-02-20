#ifdef TEST

#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <SDL.h>
#include <SDL_net.h>

TEST_CASE("SDL init") {
  REQUIRE(SDL_Init(SDL_INIT_EVERYTHING) == 0);
  SDL_Quit();
}

TEST_CASE("SDL_net init") {
  REQUIRE(SDLNet_Init() == 0);
  SDLNet_Quit();
}


#endif //  TEST
