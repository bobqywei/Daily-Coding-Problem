#include<iostream>
#include<unordered_set>
#include<string>

using namespace std;

string dominoes(string s) {
	unordered_set<int> pivots;
	for (int i = 0; i < s.length(); ++i) {
		if (s[i] != '.') pivots.insert(i);
	}

	while (!pivots.empty()) {
		unordered_set<int> tmp;
		for (const int &i : pivots) {
			int nextIndex = (s[i] == 'R' ? i + 1 : i - 1);
			if (nextIndex >= 0 && nextIndex < s.length() && pivots.find(nextIndex) == pivots.end()) {
				if (s[nextIndex] == '.') {
					s[nextIndex] = s[i];
					tmp.insert(nextIndex);
				} else if (s[nextIndex] != s[i]) {
					s[nextIndex] = '.';
					tmp.erase(nextIndex);
				}
			}
		}
		pivots = tmp;
	}

	return s;
}

int main() {
	string inp;
	cin >> inp;
	cout << dominoes(inp) << endl;
}