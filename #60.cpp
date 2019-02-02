#include <iostream>
#include <string>
#include <sstream>
#include <unordered_set>
#include <vector>

using namespace std;

bool sameSumPartition(vector<int> &arr) {
	int total = 0;
	for (int i = 0; i < arr.size(); i++) {
		total += arr[i];
	}
	if (total % 2 != 0) return false;
	total /= 2;

	unordered_set<int> sums;
	for (int i = 0; i < arr.size(); i++) {
		if (sums.find(total - arr[i]) != sums.end()) 
			return true;
		else {
			for (int sum : sums) {
				sums.insert(arr[i] + sum);
			}
			sums.insert(arr[i]);
		}
	}
	return false;
}

int main() {
	string inp;
	while (cin >> inp) {
		string token;
		istringstream ss(inp);
		vector<int> v;

		while (getline(ss, token, ',')) {
			v.push_back(stoi(token));
		}

		cout << sameSumPartition(v) << endl;
	}
}