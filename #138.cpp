#include<iostream>
#include<string>

using namespace std;

int minimum_coins_needed(int n) {
	int denom[] = {25, 10, 5, 1};
	int total_coins = 0;
	int remaining = n;
	for (int i = 0; i < 4; i++) {
		total_coins += remaining / denom[i];
		remaining %= denom[i];
	}
	return total_coins;
}

int main() {
	string inp;
	while (cin >> inp) {
		cout << "Minimum coins needed: " << minimum_coins_needed(stoi(inp)) << endl;
	}
}
