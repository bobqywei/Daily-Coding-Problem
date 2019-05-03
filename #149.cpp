#include<iostream>
#include<vector>

using namespace std;

class ListSum {
	vector<int> precomputed_sums;

public:
	ListSum(vector<int>& v) {
		int sum = 0;
		for (int i : v) {
			sum += i;
			precomputed_sums.push_back(sum);
		}
	}

	int sum(int i, int j) {
		if (i >= j) 
			return 0;
		else
			return precomputed_sums[j-1] - precomputed_sums[i-1];
	}
};

int main() {
	vector<int> v{1,2,3,4,5};
	ListSum list(v);
	cout << list.sum(1,3) << endl;
}