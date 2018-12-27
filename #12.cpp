#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

unordered_map<int, long> memo;

long countWays(int n) {
	if (memo.find(n) != memo.end()) return memo[n];
	long ret;
	if (n == 1) {
		ret = 1;
	} else if (n == 2) {
		ret = 2;
	} else {
		ret = countWays(n-1) + countWays(n-2);
	}
	memo[n] = ret;
	return memo[n];
}

int main() {
	string input;
	while (cin >> input) {
		cout << countWays(stoi(input)) << endl;
	}
}