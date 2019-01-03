#include <iostream>
#include <string>
#include <assert.h>
#include <ctype.h>

using namespace std;

string runLengthEncoding(string s) {
	char curr = '\0';
	int count = 0;
	string output = "";

	for (char c : s) {
		if (c == curr) {
			count++;
		} else {
			if (count != 0) output = output + to_string(count) + curr;
			curr = c;
			count = 1;
		}
	}
	output = output + to_string(count) + curr;

	return output;
}

string runLengthDecoding(string s) {
	assert(s.size() % 2 == 0);

	string output = "";
	for (int i = 0; i < s.size(); i+=2) {
		int count = s[i] - '0';
		char curr = s[i+1];

		for (int j = 0; j < count; j++) {
			output += curr;
		}
	}

	return output;
}

bool hasDigit(string s) {
	for (char c : s) {
		if (isdigit(c)) return true;
	}
	return false;
}

int main() {
	string inp;
	while (cin >> inp) {
		if (hasDigit(inp)) {
			cout << "Decoded Result: " << runLengthDecoding(inp) << endl;
		} else {
			cout << "Encoded Result: " << runLengthEncoding(inp) << endl;
		}
	}
}
