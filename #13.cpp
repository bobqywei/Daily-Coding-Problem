#include <unordered_map>
#include <iostream>
#include <string>

using namespace std;

void printMap(unordered_map<char, int> m) {
	for (pair<char, int> p : m) {
		cout << "{" << p.first << ", " << p.second << "}" << ", ";
	}
	cout << endl;
}

string largest_k_distinct(string s, int k) {

	// tracks frequencies of chars in current window
	unordered_map<char, int> charFreq;
	charFreq[s[0]] = 1;

	// left to right represents current window
	int left = 0;
	int right = 0;

	// distinct chars in current window
	int distinctChars = 1;

	// longest string with k distinct chars 
	int maxlen = 0;
	int start = 0;

	while (right < s.length() - 1) {

		// Moves right bound of window forward to increase distinct chars
		if (distinctChars <= k) {
			char newChar = s[++right];

			if (charFreq.find(newChar) == charFreq.end() || charFreq[newChar] == 0) {
				charFreq[newChar] = 1;
				distinctChars++;
			} else {
				charFreq[newChar]++;
			}

			if (distinctChars == k && right-left+1 > maxlen) {
				maxlen = right - left + 1;
				start = left;
			}

		// Moves left bound of window forward if distinct chars > k
		} else {
			charFreq[s[left]]--;
			if (charFreq[s[left]] == 0) distinctChars--;
			left++;
		}
	}

	return s.substr(start, maxlen);
}

int main() {
	string in;
	while (cin >> in) {
		string s;
		cin >> s;
		cout << largest_k_distinct(s, stoi(in)) << endl;
	}
}