#include<iostream>

using namespace std;

void print_arr(int arr[], int length) {
	for (int i = 0; i < length; i++) {
		cout << arr[i] << ", ";
	}
	cout << endl;
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int arr[], int left, int length) {
	for (int i = 0; i < length / 2; i++) {
		swap(&arr[left + i], &arr[left + length-1 - i]);
	}
}

void rotate(int arr[], int k, int length) {
	k %= length;
	reverse(arr, 0, k);
	reverse(arr, k, length - k);
	reverse(arr, 0, length);
}

int main() {
	int arr[] = {1,2,3,4,5,6,7};
	int length = sizeof(arr)/sizeof(arr[0]);
	print_arr(arr, length);
	rotate(arr, 4, length);
	print_arr(arr, length);
}
