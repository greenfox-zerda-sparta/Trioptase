#include "Game.hpp"


Game* Game::game_instance = NULL;

Game::Game() : nodes(map_size, vector<MapNode>(map_size, empty_field)) {
  //just for demonstration purpose:
  //vector<int> korte;
  //korte.push_back(3);
  //tile_map.push_back(korte);
  //tile_map(30, vector<int>(30, 0));
}

void Game::fill_tile_map() {

}

Game* Game::get_game_instance() {
  if (game_instance == NULL) {
    game_instance = new Game;
  }
  return game_instance;
}