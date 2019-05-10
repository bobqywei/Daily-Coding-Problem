#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

bool is_permutation_palindrome(string s) {
	unordered_map<char, int> freqs;
	for (char c : s) {
		if (freqs.find(c) != freqs.end()) {
			freqs[c] += 1;
		} else {
			freqs[c] = 1;
		}
	}
	bool has_odd = false;
	for (pair<char, int> p : freqs) {
		if (p.second % 2 != 0) {
			if (has_odd) return false;
			else has_odd = true;
		}
	}
	return true;
}

int main() {
	string test = "daily";
	cout << is_permutation_palindrome(test) << endl;
}