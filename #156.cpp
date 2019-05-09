#include<iostream>
#include<vector>
#include<climits>
#include<cstdlib>
#include<string>

using namespace std;

int least_square_composition(int n) {
	vector<int> squares;
	for (int i = 1; i*i < n; i++) {
		squares.push_back(i*i);
	}

	int min_num_squares = INT_MAX;
	for (int i = squares.size()-1; i >= 0; i--) {
		int index = i;

		int num_squares = 0;
		int remaining = n;
		while(i >= 0) {
			num_squares += remaining / squares[i];
			remaining %= squares[i];
			if (remaining == 0) {
				min_num_squares = min(min_num_squares, num_squares);
				break;
			}
			i--;
		}
	}
	return min_num_squares;
}

int main() {
	string inp;
	while(cin >> inp) {
		cout << "Fewest number of squares needed: " << least_square_composition(stoi(inp)) << endl;
	}
}