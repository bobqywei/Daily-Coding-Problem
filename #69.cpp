#include <iostream>
#include <climits>
#include <stdlib.h>

using namespace std;

int largestTripleProduct(int arr[], int n) {
	if (n == 3) return arr[0] * arr[1] * arr[2];

	int pos[] = {-1,-1,-1};
	int min_neg[] = {0,0,0};
	int max_neg[] = {INT_MIN,INT_MIN,INT_MIN};
	for (int i = 0; i < n; i++) {
		if (arr[i] > pos[0]) {
			pos[2] = pos[1];
			pos[1] = pos[0];
			pos[0] = arr[i];
		} else if (arr[i] > pos[1]) {
			pos[2] = pos[1];
			pos[1] = arr[i];
		} else if (arr[i] > pos[2]) {
			pos[2] = arr[i];
		}

		if (arr[i] < 0) {
			if (arr[i] < min_neg[0]) {
				min_neg[2] = min_neg[1];
				min_neg[1] = min_neg[0];
				min_neg[0] = arr[i];
			} else if (arr[i] < min_neg[1]) {
				min_neg[2] = min_neg[1];
				min_neg[1] = arr[i];
			} else if (arr[i] < min_neg[2]) {
				min_neg[2] = arr[i];
			}

			if (arr[i] > max_neg[0]) {
				max_neg[2] = max_neg[1];
				max_neg[1] = max_neg[0];
				max_neg[0] = arr[i];
			} else if (arr[i] > max_neg[1]) {
				max_neg[2] = max_neg[1];
				max_neg[1] = arr[i];
			} else if (arr[i] > max_neg[2]) {
				max_neg[2] = arr[i];
			}
		}
	}

	int n_pos = 0;
	int n_neg = 0;

	for (int i = 0; i < 3; i++) {
		if (pos[i] >= 0) n_pos++;
		if (min_neg[i] < 0) n_neg++;
	}

	if (n_pos == 0) return max_neg[0] * max_neg[1] * max_neg[2];

	if (n_pos == 3 && n_neg >= 2) {
		return pos[0] * max(pos[1] * pos[2], min_neg[0] * min_neg[1]);
	} else if (n_pos == 3) {
		return pos[0] * pos[1] * pos[2];
	} else if (n_neg >= 2) {
		return min_neg[0] * min_neg[1] * pos[0];
	}
}

int main() {
	int arr[] = {-10,-5,-3,2,7,-6,5,3};
	cout << largestTripleProduct(arr, sizeof(arr) / sizeof(arr[0])) << endl;
}