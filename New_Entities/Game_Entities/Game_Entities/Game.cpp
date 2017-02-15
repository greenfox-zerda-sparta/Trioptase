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

void Game::delete_game() {
  delete game_instance;
  game_instance = NULL;
}

bool is_key(string key, json obj) {
  for (json::iterator it = obj.begin(); it != obj.end(); ++it) {
    std::cout << *it << std::endl;
    if (*it == key) {
      return true;
    }
  }
  return false;
}

int Game::from_json(json msg_from_server) {
  int counter = 0;
  json nulla = {"0", nullptr};
  for (int i = 0; i < 900; i++) {
    if (msg_from_server["Map"][i] != nulla) {
      counter++;
      std::cout << is_key("Troop", msg_from_server["Map"][i][1]) << std::endl;
      //if (msg_from_server["Map"][i][1].find("Troop") == msg_from_server["Map"][i][1].end())
    }
  }
  return counter;
}

void Game::write_json_to_file(json janos) {
  ofstream file;
  file.open("json.txt");
  file << janos;
  file.close();
}

Game::~Game() {
  delete map;
  map = NULL;
}
