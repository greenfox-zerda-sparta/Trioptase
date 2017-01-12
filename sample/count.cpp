#include <iostream>

using std::cout;
using std::endl;

void count(int);

int main(int argc, char* argv[]) {
  count(26);
	return 0;
}

void count(int providedAge) {
  cout << "Hi everyone!\nI'm " << providedAge << " years old." << endl;
}
