#include "Graphic.hpp"
#include "User_input.hpp"
#include "Map.hpp"

const int WINDOW_WIDTH(640);
const int WINDOW_HEIGHT(640);
const int MAP_SIZE(10);

int main(int argc, char* argv[]) {
  
  Graphic display(WINDOW_WIDTH, WINDOW_HEIGHT);
  display.initialization();
  display.load_picture("pics/grass.bmp");
  display.load_picture("pics/building.bmp");
  display.load_picture("pics/yoda.bmp");

  User_input input(0, 0);

  Map my_map(MAP_SIZE);

  bool running = true;
  while (running) {
    input.input_handler(running);
    for (int i = 0; i < MAP_SIZE; i++) {
      for (int j = 0; j < MAP_SIZE; j++) {
        if (my_map.get_my_map_data(i, j) == 0) {
          display.draw_picture("pics/grass.bmp", WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, i, j);     
        }
      }
    }
    if (input.get_changing_y() > 64 + (float)128 * 0.2) {
      display.draw_picture("pics/building.bmp", 64, 64, 128, 128, 1, 1);
      display.draw_picture("pics/yoda.bmp", input.get_changing_x(), input.get_changing_y(), WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, 1, 1);
    }
    else {
      display.draw_picture("pics/yoda.bmp", input.get_changing_x(), input.get_changing_y(), WINDOW_WIDTH / MAP_SIZE, WINDOW_HEIGHT / MAP_SIZE, 1, 1);
      display.draw_picture("pics/building.bmp", 64, 64, 128, 128, 1, 1);
    }
    display.render_pictures();
  }
  return 0;
}