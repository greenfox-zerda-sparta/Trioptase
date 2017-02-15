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

bool has_obj_key(string key, json obj) {
  for (json::iterator it = obj.begin(); it != obj.end(); ++it) {
    if (*it == key) {
      return true;
    }
  }
  return false;
}

int Game::from_json(json msg_from_server) {
  int counter = 0;
  json empty_json = {"0", nullptr};
  for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
    if (msg_from_server["Map"][i] != empty_json) {
      counter++;
      int first_index = i / MAP_SIZE;
      int second_index = i % MAP_SIZE;
      if (has_obj_key("Troop", msg_from_server["Map"][i][1])) {
        json troop_json = msg_from_server["Map"][i][1][1];
        Troop soldier;
        soldier.set_ap(troop_json["attack"]);
        soldier.set_dp(troop_json["defense"]);
        soldier.set_hp(troop_json["health"]);
        soldier.set_price(troop_json["price"]);
        map->node_map[first_index][second_index]->set_entity(&soldier);
      }
      else if (has_obj_key("Building", msg_from_server["Map"][i][1])) {
        json bulding_json = msg_from_server["Map"][i][1][1];
        Building building;
        building.set_ap(bulding_json["attack"]);
        building.set_dp(bulding_json["defense"]);
        building.set_hp(bulding_json["health"]);
        building.set_price(bulding_json["price"]);
        map->node_map[first_index][second_index]->set_entity(&building);
      }
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
  delete map;
  map = NULL;
}
