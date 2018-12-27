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

	unordered_map<char, int> charFreq;
	charFreq[s[0]] = 1;

	int left = 0;
	int right = 0;
	int max = 0;
	int start = 0;
	int distinctChars = 1;

	while (right < s.length() - 1) {

		if (distinctChars <= k) {

			char newChar = s[++right];

			if (charFreq.find(newChar) == charFreq.end() || charFreq[newChar] == 0) {
				charFreq[newChar] = 1;
				distinctChars++;
			} else {
				charFreq[newChar]++;
			}

			if (distinctChars == k && right-left+1 > max) {
				max = right - left + 1;
				start = left;
			}

		} else {

			charFreq[s[left]]--;

			if (charFreq[s[left]] == 0) distinctChars--;

			left++;
		}
	}

	return s.substr(start, max);
}

int main() {
	string in;
	while (cin >> in) {
		string s;
		cin >> s;
		cout << largest_k_distinct(s, stoi(in)) << endl;
	}
}