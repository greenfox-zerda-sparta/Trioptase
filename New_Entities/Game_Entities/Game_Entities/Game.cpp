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
  std::cout << msg_from_server["Map"][0] << std::endl;
  int counter = 0;
  json nulla;
  nulla["0"] = NULL;
  std::cout << nulla << std::endl;
  if (msg_from_server["Map"][0] != nulla) {
    std::cout << "hallo" << std::endl;
    counter++;
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
