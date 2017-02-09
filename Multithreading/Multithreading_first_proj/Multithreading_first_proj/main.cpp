#ifndef TEST
#include <iostream>
#include <thread>


class myFunctor {
public: 
  myFunctor() {}
  void publicFunction(int var) {
    std::cout << "var is = " << var << " public function of myFunctor class is called" << std::endl;
  }
};

void print_message() {
  std::cout << "Hello threads" << std::endl;
  for (int i = 0; i < 100; i++) {
    std::cout << i << ". Hello threads" << std::endl;
  }
}

void printSomeValues(int val, char* str, double dval) {
  std::cout << val << " " << str << " " << dval << std::endl;

}

int main(int argc, char* argv[]) {
  /*
  myFunctor myFunc;
  
  std::thread functorTest(&myFunctor::publicFunction, &myFunc, 5);
  if (functorTest.joinable()) {
    functorTest.join();
  }
  */
  
  int counter = 0;
  bool run = true;
  std::thread printer(print_message);
  std::thread::id id1 = printer.get_id();

  printer.detach();
  

  while (run) {
    std::cout << "counter is = " << counter++ << std::endl;

    if (printer.joinable()) {
      printer.join();
      std::cout << "id is: " << id1 << std::endl;
    }
    else {
      std::cout << "Can not join due to detach() func" << std::endl;
    }
   
    char input;
    std::cin >> input;
    if (input == 'x') {
      run = false;
    }
  }
  
  return 0;
}

#endif