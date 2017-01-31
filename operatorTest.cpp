#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char* argv[]) {

	unsigned short int one = 0b0001;
	unsigned short int three = 0b0011;
	unsigned short int four =  0b0100;
	unsigned short int andOperator = one & three;	
	unsigned short int orOperator = one | three;
	unsigned short int notOperator = ~one;
	unsigned short int xorOperator = one ^ three;
	unsigned short int xor41 = four ^ one;
	cout << "andOperator: " << andOperator << endl;
	cout << "orOperator: " << orOperator << endl;
	cout << "notOperator: " << notOperator << endl;
	cout << "xorOperator: " << xorOperator << endl;
	cout << "xor41: " << xor41 << endl;
	return 0;
}
