//============================================================================
// Name        : cheer.cpp
// Author      : Feri
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

using namespace std;

void cheer(int number, char* baseLanguage) {
  cout << "Trioptase " << number << endl;
  cout << "my chosen base language is: " << baseLanguage << endl; 
}

int main() {
  char* lang = "c++";
  int number_of_team_members = 3;
  cheer(number_of_team_members, lang);
  return 0;
}
