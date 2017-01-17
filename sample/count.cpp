#include <iostream>

using std::cout;
using std::endl;

const int MY_AGE = 26;

void count(int);

int main(int argc, char* argv[]) {
  int month = MY_AGE * 12;
  count(MY_AGE, month);
  return 0;
}

void count(unsigned int providedAge, unsigned short int month) {
  cout << "Hi everyone!\nI'm " << providedAge << " years old." << endl;
  cout << "And I was born in " << month << ". month" << endl;
  cout << "Akkor megbaszom a tiédet!" << endl;
}
