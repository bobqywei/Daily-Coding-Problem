#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <stdlib.h>
#define INT_SIZE 31

using namespace std;

int nonDuplicatedInteger(vector<int> &v) {
	int ret = 0;

	for (int i = 0; i < INT_SIZE; i++) {
		int sum = 0;
		int mask = 1 << i;

		for (int j : v) {
			if ((j & mask) != 0) sum++;
		}

		if (sum % 3 != 0) {
			ret |= mask;
		}
	}

	return ret;
}

int main() {
	string inp;
	cin >> inp;
	istringstream ss(inp);
	string token;

	vector<int> v;
	while (getline(ss, token, ',')) {
		v.push_back(stoi(token));
	}

	cout << nonDuplicatedInteger(v) << endl;
}