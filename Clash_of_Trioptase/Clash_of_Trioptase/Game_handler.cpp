#include "Game_handler.hpp"

Game_handler::Game_handler() {
  this->window = new Window(WINDOW_WIDTH + PANEL_WIDTH, WINDOW_HEIGHT);
  this->drawer = new Texture_manager(WINDOW_WIDTH, WINDOW_HEIGHT, PANEL_WIDTH);
  this->ui = new User_input(WINDOW_WIDTH, WINDOW_HEIGHT);
  this->selected_coordinates.first = 0;
  this->selected_coordinates.second = 0;
}

void Game_handler::initialization() {
  drawer->load("pictures/wallpaper.jpg", "background", 1920, 1080, window->get_renderer());
  drawer->load("pictures/64x64.png", "troop", 64, 64, window->get_renderer());
  drawer->load("pictures/building.png", "building", 64, 64, window->get_renderer());
  drawer->load("pictures/panel.png", "panel", 260, 640, window->get_renderer());
  drawer->load("pictures/smoke.png", "smoke", 64, 64, window->get_renderer());

  Game_logic::get_game_instance()->map->init_map();
}

void Game_handler::run() {
  
  bool running = true;
  while (running) {    
    ui->input_handler(running, this->selected_coordinates);

    window->render_clear();

    drawer->dynamically_background("background", 0, 0, ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    drawer->dynamically_all_tile(ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());
    drawer->dynamically_one_tile("smoke", ui->get_changing_x(), ui->get_changing_y(), ui->get_changing_mouse_x(), ui->get_changing_mouse_y(), window->get_renderer());

    {
      drawer->statically("panel", WINDOW_WIDTH, 0, window->get_renderer());
      drawer->statically("building", WINDOW_WIDTH + 40, 60, window->get_renderer());      
      drawer->statically("troop", WINDOW_WIDTH + 40, 144 + 190, window->get_renderer());
    }

    if (selected_coordinates.first != 0) {
      Game_logic::get_game_instance()->create_building(selected_coordinates.first, selected_coordinates.second);
    }
    window->render_present();
  }
}

void Game_handler::deinitialization() {
  window->close();
}

Game_handler::~Game_handler() {
  delete this->window;
  delete this->drawer;
  delete this->ui;
}