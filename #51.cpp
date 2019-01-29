#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shuffle(int *arr, int size) {
	int curr = 0;
	while (curr < size-1) {
		int index = rand() % (size - curr);
		swap(&arr[curr], &arr[index]);
		curr++;
	}
}

int main() {
	srand(time(NULL));
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	shuffle(arr, sizeof(arr)/sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr)/sizeof(arr[0]); i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}