#include "Game.hpp"

Game* Game::game_instance = NULL;

Game::Game() {
  map = new Map;
}

Game* Game::get_game_instance() {
  if (game_instance == NULL) {
    game_instance = new Game;
  }
  return game_instance;
}

Game::~Game() {
  delete game_instance;
  game_instance = NULL;
  delete map;
  map = NULL;
}
