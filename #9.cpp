#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

int largestNonAdjacentSum(vector<int> &v) {
	int sumExcl = 0;
	int sumIncl = v[0];

	for (int i = 1; i < v.size(); i++) {
		int temp = max(sumExcl, sumIncl);
		sumIncl = sumExcl + v[i];
		sumExcl = temp;
	}

	return max(sumExcl, sumIncl);
}

int main() {
	string input;
	while (getline(cin, input)) {
		vector<int> v;
		istringstream ss(input);
		string token;
		while (getline(ss, token, ',')) {
			v.push_back(stoi(token));
		}
		cout << largestNonAdjacentSum(v) << endl;
	}
}