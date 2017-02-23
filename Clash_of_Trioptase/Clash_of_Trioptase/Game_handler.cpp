#include "Game_handler.hpp"

void Game_handler::static_panel() {
  drawer->statically("panel_grid", WINDOW_WIDTH, 0, window->get_renderer());
  drawer->statically("static_building", WINDOW_WIDTH + 80, 84, window->get_renderer());
  drawer->statically("static_troop", WINDOW_WIDTH + 80, 80 + 190, window->get_renderer());
}

void Game_handler::select_building_from_panel(bool& clicked) {
  if (selected_coordinates.first > 32 && selected_coordinates.first < 36 && selected_coordinates.second > 2 && selected_coordinates.second < 6) {
    drawer->statically("building_selected", WINDOW_WIDTH + 80, 84, window->get_renderer());
    clicked = true;
  }
}

void Game_handler::pin_building(bool& clicked) {
  if (clicked) {
    if (selected_coordinates.first > 0 && selected_coordinates.first < 29) {
      Game_logic::get_game_instance()->create_building(selected_coordinates.first, selected_coordinates.second);
      clicked = false;
    }
  }
}

void Game_handler::select_troop_from_panel(bool& clicked) {
  if (selected_coordinates.first > 32 && selected_coordinates.first < 36 && selected_coordinates.second > 11 && selected_coordinates.second < 15) {
    drawer->statically("troop_selected", WINDOW_WIDTH + 80, 80 + 190, window->get_renderer());
    clicked = true;
  }
}

void Game_handler::pin_troop(bool& clicked) {
  if (clicked) {
    if (selected_coordinates.first > 0 && selected_coordinates.first < 29) {
      Game_logic::get_game_instance()->create_troop(selected_coordinates.first, selected_coordinates.second);        
      clicked = false;
    }
  }
}

void Game_handler::show_enemy_village(bool & clicked) {
}

Game_handler::Game_handler() {
  this->window = new Window(WINDOW_WIDTH + PANEL_WIDTH, WINDOW_HEIGHT);
  this->drawer = new Texture_manager(WINDOW_WIDTH, WINDOW_HEIGHT, PANEL_WIDTH);
  this->ui = new User_input(WINDOW_WIDTH, WINDOW_HEIGHT);
  this->selected_coordinates.first = 0;
  this->selected_coordinates.second = 0;
  bool select_building = false;
}

void Game_handler::initialization() {
  drawer->load("pictures/wallpaper.jpg", "background", 1920, 1080, window->get_renderer());
  drawer->load("pictures/troop.png", "troop", 64, 64, window->get_renderer());
  drawer->load("pictures/building.png", "building", 64, 64, window->get_renderer());
  drawer->load("pictures/building.png", "static_building", 32, 32, window->get_renderer());
  drawer->load("pictures/building_selected.png", "building_selected", 32, 32, window->get_renderer());
  drawer->load("pictures/troop.png", "static_troop", 32, 32, window->get_renderer());
  drawer->load("pictures/troop_selected.png", "troop_selected", 32, 32, window->get_renderer());
  drawer->load("pictures/panel.png", "panel", 260, 640, window->get_renderer());
  drawer->load("pictures/panel_grid.png", "panel_grid", 260, 640, window->get_renderer());
  drawer->load("pictures/smoke.png", "smoke", 64, 64, window->get_renderer());

  Game_logic::get_game_instance()->map->init_map();
}

void Game_handler::run() {  
  Game_logic::get_game_instance()->update_map_from_json(Game_logic::get_game_instance()->read_json_from_file("Game_saves/json.json"));  
  bool running = true;
  while (running) {    
    ui->input_handler(running, this->selected_coordinates);

    window->render_clear();

    drawer->dynamically_background("background", 0, 0, ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    drawer->dynamically_all_tile(ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    drawer->dynamically_one_tile("smoke", ui->get_changing_x(), ui->get_changing_y(), ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    
    this->static_panel();
    
    this->select_building_from_panel(select_building);
    this->pin_building(select_building);
    this->select_troop_from_panel(select_troop_on_panel);
    this->pin_troop(select_troop_on_panel);

    window->render_present();
  }
 Game_logic::get_game_instance()->write_json_to_file(Game_logic::get_game_instance()->map->to_json(), "Game_saves/json.json");
}

void Game_handler::deinitialization() {
  window->close();
}

Game_handler::~Game_handler() {
  delete this->window;
  delete this->drawer;
  delete this->ui;
}