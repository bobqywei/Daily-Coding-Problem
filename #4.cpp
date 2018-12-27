#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int moveNegToFront(int arr[], int size) {
	int start = 0;
	
	for (int i = 0; i < size; i++) {
		if (arr[i] <= 0) {
			swap(&arr[i], &arr[start]);
			start++;
		}
	}

	return start;
}

int lowestMissingNum(int arr[], int size) {

	int start = moveNegToFront(arr, size);

	for (int i = start; i < size; i++) {
		int index = abs(arr[i]) - 1 + start;
		if (index < size && arr[index] > 0) arr[index] *= -1;
	}

	for (int i = start; i < size; i++) {
		if (arr[i] > 0) return i - start + 1;
	}

	return size - start + 1;
}

int main() {
	int arr[11] = {-1, 4, 3, -100, 2, 5, 9, 8, -2, 6, 1};
	cout << lowestMissingNum(arr, sizeof(arr) / sizeof(int)) << endl;
}