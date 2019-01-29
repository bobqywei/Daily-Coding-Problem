#include <iostream>
#include <stdlib.h>

using namespace std;

int maxContiguousSum(int *arr, int size) {
	int maxSum = -1;
	int currSum = 0;

	for (int i = 0; i < size; i++) {
		currSum = max(0, currSum + arr[i]);
		maxSum = max(currSum, maxSum);
	}

	return maxSum;
}

int main() {
	int arr[] = {30, 34, -50, 42, 14, -5, 86};
	int arr2[] = {-5, -1, -8, -9};
	cout << maxContiguousSum(arr, sizeof(arr)/sizeof(arr[0])) << endl;
}