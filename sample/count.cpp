#include <iostream>

using std::cout;
using std::endl;

void count(int);

int main(int argc, char* argv[]) {
  count(26);
  return 0;
}

void count(int providedAge) {
  int age = providedAge;
  cout << "Hi everyone!\nI'm " << age << " years old." << endl;
}
