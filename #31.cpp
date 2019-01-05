#include <iostream>
#include <string>
#include <stdlib.h>
#include <map>

using namespace std;

map<pair<string, string>, int> memo;

int minEditDistance(string s1, string s2) {
	int len1 = s1.length();
	int len2 = s2.length();
	pair<string, string> p = make_pair(s1, s2);

	// return if already computed
	if (memo.find(p) != memo.end()) return memo[p];

	// len2 number of insertions required
	if (len1 == 0) {
		memo[p] = len2;
		return memo[p];
	}

	// len1 number of deletions required
	if (len2 == 0) {
		memo[p] = len1;
		return memo[p];
	}

	// if ending characters match then cut both
	if (s1[len1-1] == s2[len2-1]) {
		memo[p] = minEditDistance(s1.substr(0, len1-1), s2.substr(0, len2-1));	
		return memo[p];
	} 

	// insertion at end of s1 to match s2 
	int insertion = minEditDistance(s1, s2.substr(0, len2-1));
	// deletion at end of s1
	int deletion = minEditDistance(s1.substr(0, len1-1), s2);
	// replacement at end of s1 to match s2
	int replace = minEditDistance(s1.substr(0, len1-1), s2.substr(0, len2-1));

	// return lowest number of edits plus 1
	memo[p] = min(insertion, min(deletion, replace)) + 1;
	return memo[p];
}

int main() {
	string inp;
	while (cin >> inp) {
		string s1 = inp;
		cin >> inp;
		string s2 = inp;
		cout << "Minimum edit distance is " << minEditDistance(s1, s2) << "." << endl;
	}
}