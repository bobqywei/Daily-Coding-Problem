#include<iostream>

using namespace std;

pair<int, int> get_nonrepeated_nums(int arr[], int n) {
	int running_xor = 0;
	for (int i = 0; i < n; i++) {
		running_xor ^= arr[i];
	}
	// here, running_xor == a ^ b, so any set bit in running_xor
	// means that a and b differ at this bit
	int rightmost_set_bit = running_xor & ~(running_xor - 1);

	// split the list into two partitions
	int a = 0;
	int b = 0;
	for (int i = 0; i < n; i++) {
		// numbers with single bit set
		if ((arr[i] & rightmost_set_bit) == 0) a ^= arr[i];
		// numbers with single bit not set
		else b ^= arr[i];
	} 
	return make_pair(a, b);
}

int main() {
	int arr[] = {2,4,6,8,10,2,6,10,8,-3};
	pair<int, int> result = get_nonrepeated_nums(arr, sizeof(arr)/sizeof(arr[0]));
	cout << "The two non-repeated numbers are " << result.first << " and " << result.second << endl;
}
