#include <iostream>

using namespace std;

void printname(char*);

int main(int argc, char* argv[]) {
  printname("Danika");
  return 0;
}

void printname(char* name) {
  cout << "Greetings" << endl;
  cout << "My name is: " << name;
  cout << " and I was born in " << 5 << ". month";
}
