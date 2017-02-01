#include "Game.hpp"

Game* Game::game_instance = NULL;

Game::Game() {
  //just for demonstration purpose:
  vector<int> korte;
  korte.push_back(3);
  tile_map.push_back(korte);
}

Game* Game::get_game_instance() {
  if (game_instance == NULL) {
    game_instance = new Game;
  }
  return game_instance;
}