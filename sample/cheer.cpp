//============================================================================
// Name        : cheer.cpp
// Author      : Feri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

void cheer(int number) {
  cout << "Trioptase " << number << endl;
}

int main() {
  int number_of_team_members = 3;
  cheer(number_of_team_members);
	return 0;
}
