#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

int find_majority(vector<int>& v) {
	int threshold = v.size() / 2;
	unordered_map<int, int> freqs;
	for (int i : v) {
		freqs[i] = (freqs.find(i) != freqs.end() ? freqs[i] + 1 : 1);
		if (freqs[i] >= threshold) return i; 
	}
	return -1;
}

int main() {
	vector<int> v = {1,2,1,1,3,4,0};
	int result = find_majority(v);
	if (result == -1) {
		cout << "No majority element." << endl;
	} else {
		cout << result << endl;
	}
}