#include <iostream>
#include <bitset>

using std::cout;
using std::endl;
using std::bitset;

const int BITSETSIZE = 8;

void printOutBitset(bitset<BITSETSIZE> thisSet);

int main(int argc, char* argv[]) {

	bitset<BITSETSIZE> nodeValue;

	printOutBitset(nodeValue);
	cout << "size: " << nodeValue.size() << endl;
	cout << "none: " << nodeValue.none() << endl;
	nodeValue.set(0);
	nodeValue.set(7);
	nodeValue.set(6);
	nodeValue.set(5);
	
	cout << "any: " << nodeValue.any() << endl;
	printOutBitset(nodeValue);

	const unsigned int node = (unsigned int)(nodeValue.to_ulong());
	const unsigned int low = 0xF;
	const unsigned int high = 0xF0;
	unsigned int nodeForLow = node;
	unsigned int nodeLow = nodeForLow &= low;
	cout << "nodeLow ( node: " << node << " &= low: " << low << "): " << nodeLow << endl;
	unsigned int nodeForHigh = node;
	unsigned int nodeHigh = nodeForHigh &= high;
	cout << "nodeHigh ( node: " << node << " &= high: " << high << "): " << nodeHigh << endl;
	
	return 0;
}

void printOutBitset(bitset<BITSETSIZE> thisSet) {
	int size = thisSet.size() - 1;
	for (int i = size; i >= 0; i--) {
		cout << "[" << i << "]" << thisSet[i] << " ";
	}
	cout << endl;
}
