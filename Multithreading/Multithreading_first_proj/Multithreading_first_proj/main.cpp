#ifndef TEST
#include <iostream>
#include <thread>

void print_message() {
  std::cout << "Hello threads" << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << i << ". Hello threads" << std::endl;
  }
}

int main(int argc, char* argv[]) {
  std::thread printer(print_message);
  printer.detach();
  if (printer.joinable()) {
    printer.join();
  }
  else {
    std::cout << "Can not join due to detach() func" << std::endl;
  }
  return 0;
}

#endif