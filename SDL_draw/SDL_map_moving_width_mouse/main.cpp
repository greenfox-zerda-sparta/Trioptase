#include "Window.hpp"
#include "Graphic.hpp"
#include "User_input.hpp"
#include "Map.hpp"
#include "Texture_manager.hpp"

const int WINDOW_WIDTH(640);
const int WINDOW_HEIGHT(640);
const int MAP_SIZE(10);

int main(int argc, char* argv[]) {

  Window win(WINDOW_WIDTH, WINDOW_HEIGHT);

  User_input input;

  Texture_manager text_man(WINDOW_WIDTH, WINDOW_HEIGHT);

  text_man.load("pics/wallpaper.jpg", "move", 1920, 1080, win.get_renderer());
  text_man.load("pics/64x64.png", "yoda", 64, 64, win.get_renderer());
  text_man.load("pics/building.bmp", "builing", 128, 128, win.get_renderer());

  bool running = true;
  while (running) {
    input.input_handler(running);
    win.render_clear();
    
    text_man.draw("move", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, win.get_renderer());
    text_man.draw_frame("move", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, input.get_changing_mouse_x(), input.get_changing_mouse_y(), win.get_renderer());
    
    text_man.draw("yoda", input.get_changing_x(), input.get_changing_y(), 64, 64, win.get_renderer());

    if (input.get_changing_y() > 64 + (float)128 * 0.2) {
   
    }
    else {
      
    }

    win.render_present();
  }
  win.close();

  /*
  Window win(WINDOW_WIDTH, WINDOW_HEIGHT);

  Graphic graph;

  graph.load_picture("pics/grass.bmp", win.get_renderer(), win.get_window());
  graph.load_picture("pics/building.bmp", win.get_renderer(), win.get_window());
  graph.load_picture("pics/yoda.bmp", win.get_renderer(), win.get_window());
  
  User_input input(0, 0);
  Map my_map(MAP_SIZE);

  bool running = true;
  while (running) {
    input.input_handler(running);
    for (int i = 0; i < MAP_SIZE; i++) {
      for (int j = 0; j < MAP_SIZE; j++) {
        if (my_map.get_my_map_data(i, j) == 0) {
          graph.draw_picture("pics/grass.bmp", win.get_renderer(), WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, i, j);
        }
      }
    }
    if (input.get_changing_y() > 64 + (float)128 * 0.2) {
      graph.draw_picture("pics/building.bmp", win.get_renderer(), 64, 64, 128, 128, 1, 1);
      graph.draw_picture("pics/yoda.bmp", win.get_renderer(), input.get_changing_x(), input.get_changing_y(), WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, 1, 1);
    }
    else {
      graph.draw_picture("pics/yoda.bmp", win.get_renderer(), input.get_changing_x(), input.get_changing_y(), WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, 1, 1);
      graph.draw_picture("pics/building.bmp", win.get_renderer(), 64, 64, 128, 128, 1, 1);
    }
    win.render_present();
  }
  win.close();
  */
  return 0;
}