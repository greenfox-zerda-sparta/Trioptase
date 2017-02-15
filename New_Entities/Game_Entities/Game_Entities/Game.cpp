#include "Game.hpp"
#include <fstream>

using std::ifstream;
using std::ofstream;
using std::fstream;

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

int Game::from_json(json msg_from_server) {
  int counter = 0;
  json nulla = {"0", nullptr};
  for (int i = 0; i < 900; i++) {
    if (msg_from_server["Map"][i] != nulla) {
      counter++;
    }
  }
  return counter;
}

void Game::write_json_to_file(json janos) {
  ofstream file;
  file.open("json.json");
  file << janos;
  file.close();
}

Game::~Game() {
  delete game_instance;
  game_instance = NULL;
  delete map;
  map = NULL;
}
