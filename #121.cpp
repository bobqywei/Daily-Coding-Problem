#include<string>
#include<iostream>

using namespace std;

bool recursive_check(const string& s, const int num_deletions, int left, int right) {
	if (left == right) return true;

	for (int i = 0; i < (right-left+1) / 2; i++) {
		bool no_match = s[left + i] != s[right - i];

		// Try deleting left and right chars, if deletions still remaining
		if (no_match && num_deletions > 0)
			return recursive_check(s, num_deletions - 1, left + i + 1, right - i) ||
				   recursive_check(s, num_deletions - 1, left + i, right - i - 1);
		// Not possible if current chars don't match and no deletions remaining
		else if (no_match && num_deletions == 0)
			return false; 
	}
	
	return true;
}

bool can_be_palindrome(const string& s, const int num_deletions) {
	if (s.length() < 2) return true;
	return recursive_check(s, num_deletions, 0, s.length() - 1);
}

int main() {
	string inp;
	while (cin >> inp) {
		string s = inp;
		cin >> inp;
		int k = stoi(inp);

		bool result = can_be_palindrome(s, k);
		cout << (result ? "True" : "False") << endl;
	}
}
