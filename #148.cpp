#include<iostream>
#include<string>
#include<cmath>
#include<vector>

using namespace std;

string to_binary(int val, int n) {
	int remaining = val;
	string ret = "";

	for (int i = 0; i < n; i++) {
		int decr = pow(2, n-1-i);
		if (remaining > 0 && decr <= remaining) {
			ret += "1";
			remaining -= decr;
		} else {
			ret += "0";
		}
	}
	return ret;
}

vector<int> gray_code(int n) {
	vector<int> code{0};

	// bit shift left and increment by 1
	int curr = 0;
	for (int i = 0; i < n; i++) {
		curr = (curr << 1) + 1;
		code.push_back(curr);
	}

	// bit shift left and truncate at bit position n
	int mask = pow(2, n) - 1;
	for (int i = 0; i < n-1; i++) {
		curr = (curr << 1) & mask;	
		code.push_back(curr);
	}

	return code;
}

int main() {
	string inp;
	while(cin >> inp) {
		int n = stoi(inp);
		vector<int> code = gray_code(n);
		for (int i : code) {
			cout << to_binary(i, n) << ", ";
		}
		cout << endl;
	}
}