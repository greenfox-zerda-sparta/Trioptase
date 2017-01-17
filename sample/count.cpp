#include <iostream>

using std::cout;
using std::endl;

void count(int);

int main(int argc, char* argv[]) {
  count(26);
  return 0;
}

void count(unsigned int providedAge, unsigned short int month) {
  cout << "Hi everyone!\nI'm " << providedAge << " years old." << endl;
  cout << "And I was born in " << month << ". month" << endl;
  cout << "Akkor megbaszom a tiédet!" << endl;
}
