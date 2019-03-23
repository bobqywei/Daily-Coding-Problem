#include<iostream>
#include<string>
#include<sstream>

using namespace std;

bool is_substring(string s1, string s2) {
	int index1 = 0;
	int index2 = 0;

	while (index1 < s1.length()) {
		if (s1[index1++] == s2[index2]) {
			index2++;
			if (index2 == s2.length()) return true;
		} else {
			index2 = 0;
		}
	}
	return false;
}

bool is_rotation(string s1, string s2) {
	if (s1.length() != s2.length()) return false;
	return is_substring(s1 + s1, s2);
}

int main() {
	string inp;
	while (getline(cin, inp)) {
		string s1, s2;
		istringstream ss(inp);
		ss >> s1;
		ss >> s2;

		if (is_rotation(s1, s2)) cout << "True" << endl;
		else cout << "False" << endl;
	}
}
