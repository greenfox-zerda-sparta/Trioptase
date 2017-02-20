#include "Game_logic.hpp"
#include <fstream>

using std::ofstream;

Game_logic* Game_logic::game_instance = NULL;

Game_logic::Game_logic() {
  this->map = new Map();
}

Game_logic* Game_logic::get_game_instance() {
  if (game_instance == NULL) {
    game_instance = new Game_logic;
  }
  return game_instance;
}

void Game_logic::delete_game() {
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

void Game_logic::create_troop_on_map(int first_index, int second_index, json object) {
  Troop soldier;
  soldier.set_ap(object["attack"]);
  soldier.set_dp(object["defense"]);
  soldier.set_hp(object["health"]);
  soldier.set_price(object["price"]);
  map->node_map[first_index][second_index]->set_entity(&soldier);
}

void Game_logic::create_building_on_map(int first_index, int second_index, json object) {
  Building building;
  building.set_ap(object["attack"]);
  building.set_dp(object["defense"]);
  building.set_hp(object["health"]);
  building.set_price(object["price"]);
  map->node_map[first_index][second_index]->set_entity(&building);
}

void Game_logic::create_building(int first_index, int second_index) {
  Building building;
  building.set_ap(10);
  building.set_dp(10);
  building.set_hp(10);
  building.set_price(10);
  map->node_map[first_index][second_index]->set_entity(&building);
}

void Game_logic::update_map_from_json(json msg_from_server) {
  json empty_json = {"0", nullptr};
  for (int i = 0; i < MAP_SIZE * MAP_SIZE; i++) {
    if (msg_from_server["Map"][i] != empty_json) {
      int first_index = i / MAP_SIZE;
      int second_index = i % MAP_SIZE;
      if (has_obj_key("Troop", msg_from_server["Map"][i][1])) {
        json troop_json = msg_from_server["Map"][i][1][1];
        create_troop_on_map(first_index, second_index, troop_json);
      }
      else if (has_obj_key("Building", msg_from_server["Map"][i][1])) {
        json building_json = msg_from_server["Map"][i][1][1];
        create_building_on_map(first_index, second_index, building_json);
      }
    }
  }
}

void Game_logic::write_json_to_file(json janos) {
  ofstream file;
  file.open("json.json");
  file << janos;
  file.close();
}

Game_logic::~Game_logic() {
  delete map;
  map = NULL;
}
