#include<iostream>
#include<string>

using namespace std;

uint8_t swapEvenOdd(uint8_t i) {
	return ((i >> 1) & 85) | ((i << 1) & 170);
}

int main() {
	string inp;
	while(cin >> inp) {
		int i = stoi(inp);

		if (i >= 0 && i <= 255) {
			uint8_t num = (uint8_t)i;
			num = swapEvenOdd(num);
			cout << "Even-Odd swapped: " << (int)num << endl;
		} else {
			cout << "Must be uint8" << endl;
		}
	}
}