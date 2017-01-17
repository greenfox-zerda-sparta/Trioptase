//============================================================================
// Name        : cheer.cpp
// Author      : Feri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

const int TEAM_SIZE = 3;

void cheer(int number, char* baseLanguage) {
  cout << "Trioptase " << number << endl;
  cout << "my chosen base language is: " << baseLanguage << endl; 
}

int main() {
  char* lang = "c++";
  cheer(TEAM_SIZE, lang);
  return 0;
}
