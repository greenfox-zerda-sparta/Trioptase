#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {

	const unsigned char isHungry = 0x01;
	const unsigned char isSad = 0x02;
	const unsigned char isMad = 0x04;
	const unsigned char isHappy = 0x08;
	const unsigned char isLaughing = 0x10;
	const unsigned char isAsleep = 0x20;
	const unsigned char isDead = 0x40;
	const unsigned char isCrying = 0x80;

	unsigned char me = 0;

	me |= isHappy | isLaughing;
	me &= ~isLaughing;

	cout << "Am I happy?" << static_cast<bool>(me & isHappy) << endl;
	cout << "Am I laughing?" << static_cast<bool>(me & isLaughing) <<endl;

	return 0;
}

