#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<stdlib.h>
#include<iostream>
#include<string>
#include<sstream>
using namespace std;

int find_consec(int curr, bool left, unordered_set<int>& S, unordered_map<int, int>& memo) {	
	if (S.find(curr) == S.end()) return 0;
	if (memo.find(curr) != memo.end()) return memo[curr];
	if (left) memo[curr] = 1 + find_consec(curr-1, true, S, memo);
	else memo[curr] = 1 + find_consec(curr+1, false, S, memo);
	return memo[curr];
}

int longest_consec_seq(vector<int> &v) {
	unordered_set<int> S;
	unordered_map<int, int> longest_left;
	unordered_map<int, int> longest_right;
	
	for (int i : v) {
		if (S.find(i) == S.end()) S.insert(i);
	}

	int longest = -1;
	for (int i : S) {
		int left = find_consec(i, true, S, longest_left);
		int right = find_consec(i, false, S, longest_right);
		longest = max(longest, max(left, right));
	}
	return longest;
}

int main() {
	string inp;
	getline(cin, inp);
	istringstream ss(inp);
	string token;
	vector<int> v;
	while (ss >> token) {
		v.push_back(stoi(token));
	}
	cout << "Longest Consecutive Sequence: " << longest_consec_seq(v) << endl;
}
