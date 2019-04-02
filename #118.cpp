#include<iostream>

using namespace std;

void reverse(int arr[], int left, int right) {
	if (right <= left) return;
	int len = right - left + 1;
	for (int i = 0; i < len / 2; i++) {
		int temp = arr[left+i];
		arr[left+i] = arr[right-i];
		arr[right-i] = temp;
	}
}

void square_and_sort(int arr[], int n) {
	// Find index of last negative number
	int index = -1;
	while (index + 1 < n && arr[index + 1] < 0) {
		index++;
	}

	// Reverse the negative numbers in array
	reverse(arr, 0, index);

	int temp[n];
	int i = 0;
	int j = 0;
	int k = index + 1;

	// Merge the squares of the two sorted subportions of the array
	while (j <= index && k < n) {
		if (arr[j] * arr[j] < arr[k] * arr[k])
			temp[i++] = arr[j] * arr[j++];
		else
			temp[i++] = arr[k] * arr[k++];
	}

	while (j <= index) {
		temp[i++] = arr[j] * arr[j++];
	}

	while (k < n) {
		temp[i++] = arr[k] * arr[k++];
	}

	for (int count = 0; count < n; count++) {
		arr[count] = temp[count];
	}
}

int main() {
	int arr[] = {-9,-6,-2,0,2,3,5};
	square_and_sort(arr, sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		cout << arr[i] << ",";
	}
	cout << endl;
}
