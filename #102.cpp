#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

vector<int>* subarray_from_indices(vector<int>& v, int left, int right) {
	vector<int>* ret = new vector<int>;
	for (int i = left; i <= right; i++) {
		ret->push_back(v[i]);
	}
	return ret;
}

vector<int>* contiguous_sum(vector<int>& v, int sum) {
	unordered_map<int, int> array_sums;
	int curr_sum = 0;

	for (int i = 0; i < v.size(); i++) {
		curr_sum += v[i];

		if (curr_sum == sum) return subarray_from_indices(v, 0, i);

		else if (array_sums.find(curr_sum - sum) != array_sums.end()) 
			return subarray_from_indices(v, array_sums[curr_sum - sum] + 1, i);
		
		else array_sums[curr_sum] = i;
	}

	return nullptr;
}

int main() {
	vector<int> v = {-10,0,50,-30,-20,10};
	int k = 20;

	vector<int>* result = contiguous_sum(v, k);

	if (result == nullptr) 
		cout << "No sub-array found." << endl;
	else {
		cout << "sum([";
		for (int i : *result) {
			cout << i << ",";
		}
		cout << "]) == " << k << endl;
	} 
}