#include <iostream>

using namespace std;

int getDecPair(int arr[], int size, int ignore) {
	for (int i = 0; i < size - 1; i++) {
		if (i != ignore && i+1 != ignore) {
			if (arr[i+1] < arr[i]) return i;
		} else if (i+1 == ignore) {
			if (arr[i+2] < arr[i]) return i;
		}
	}
	return -1;
}

int rmOneNonDecreasing(int arr[], int size) {
	int decIndex = getDecPair(arr, size, -1);
	if (decIndex == -1) return 0;

	int result1 = getDecPair(arr, size, decIndex);
	if (result1 == -1) return decIndex; 

	int result2 = getDecPair(arr, size, decIndex+1);
	return (result2 == -1) ? decIndex+1 : -1;
}

int main() {
	int arr[] = {5,6};
	int result = rmOneNonDecreasing(arr, sizeof(arr) / sizeof(arr[0]));
	
	if (result != -1) {
		cout << "Yes, array can be made non-decreasing by changing " << arr[result] << " at index " << result << endl;
	} else {
		cout << "No, array can not be made non-decreasing in one move" << endl;
	}
}