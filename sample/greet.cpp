#include <iostream>

using namespace std;

void printname(char*);

int main(int argc, char* argv[]) {
  printname("Danika");
  return 0;
}

void printname(char* name) {
  cout << "My name is: " << name;
}
