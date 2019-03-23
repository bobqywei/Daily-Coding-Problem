#include<iostream>
#include<unordered_map>
#include<stdlib.h>

using namespace std;

bool set_and_return(unordered_map<int, bool>& memo, int key, bool ret) {
	memo[key] = ret;
	return memo[key];
}

bool result_from_index(int curr, int hops[], int n, unordered_map<int, bool>& memo) {
	if (memo.find(curr) != memo.end()) return memo[curr];
	if (curr == n - 1) return true;

	int max_hops = min(hops[curr], (n-1) - curr);
	for (int i = 1; i <= max_hops; i++) {
		if (result_from_index(curr + i,  hops, n, memo)) 
			return set_and_return(memo, curr, true);
	}

	return set_and_return(memo, curr, false);
}

bool can_reach_last_index(int hops[], int n) {
	unordered_map<int, bool> memo;
	return result_from_index(0, hops, n, memo);
}

int main() {
	int hops[] = {2, 0, 1, 0};
	cout << (can_reach_last_index(hops, sizeof(hops)/sizeof(hops[0])) ? "True" : "False") << endl;
}