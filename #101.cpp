#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<bool> generate_sieve(int n) {
	vector<bool> isPrime;
	for (int i = 0; i <= n; i++) {
		isPrime.push_back(true);
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			int count = 2 * i;
			while (count <= n) {
				isPrime[count] = false;
				count += i;
			}
		}
	}

	return isPrime;
}

pair<int, int> prime_pair(int n, vector<bool> &sieve) {
	for (int i = 2; i < n-1; i++) {
		if (sieve[i] && sieve[n - i]) {
			return make_pair(i, n - i);
		}
	}
	return make_pair(-1, -1);
}

int main() {
	vector<bool> sieve = generate_sieve(10000000);

	string inp;
	while (cin >> inp) {
		int n = stoi(inp);
		pair<int, int> ret = prime_pair(n, sieve);

		if (ret.first == -1)
			cout << "No possible pair of primes." << endl;
		else
			cout << "Prime pairs: " << ret.first << ", " << ret.second << endl;
	}
}
