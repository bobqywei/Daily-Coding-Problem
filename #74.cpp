#include <iostream>
#include <math.h>
#include <string>
#include <stdlib.h>

using namespace std;

int freqInTable(int n, int x) {
	int root = floor(sqrt(x));
	if (n < root) return 0;

	int freq = 0;
	for (int i = 1; i <= root; i++) {
		if (x % i == 0) {
			int factor = x / i;
			if (factor == i)
				freq ++;
			else if (factor <= n)
				freq += 2;
		}
	}
	return freq;
}

int main() {
	string inp;
	cout << "Enter size of multiplication table N: ";
	cin >> inp;
	int N = stoi(inp);
	cout << "Enter int X: ";
	cin >> inp;
	int X = stoi(inp);
	cout << "There are " << freqInTable(N, X) << " in the table." << endl;
}