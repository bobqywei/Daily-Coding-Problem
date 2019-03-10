#include<iostream>
#include<vector>

using namespace std;

template<class T>
void print_vector(vector<T>& v) {
	for (T i : v) {
		cout << i << ",";
	}
	cout << endl;
}

// swap in-place without extra memory
template<class T>
void swap(T* a, T* b) {
	if (a == b) return;
	*a += *b;
	*b = *a - *b;
	*a -= *b;
}

// return next lexicographically larger permutation
template<class T>
void next_larger_permutation(vector<T>& v) {

	// search right to left for descending pair
	for (int i = v.size()-2; i >= 0; i--) {
		// found index i to be swapped
		if (v[i] < v[i+1]) {

			// search right of i for value to swap with
			for (int j = i + 1; j < v.size(); j++) {
				if (v[j] <= v[i]) {
					swap(&(v[j-1]), &(v[i]));
					break;
				}
				// swap with last element if necessary
				if (j == v.size()-1) swap(&(v[j]), &(v[i]));
			}

			// reverse all values right of index i
			for (int k = 0; k <= ((v.size()-1) - (i+1)) / 2; k++) {
				swap(&(v[(i+1) + k]), &(v[(v.size()-1) - k]));
			}
			break;
		}

		// if descending pair is not found
		// no greater permutation possible
		if (i == 0) {
			// return smallest permutation by reversing everything
			for (int k = 0; k <= (v.size()-1) / 2; k++) {
				swap(&(v[k]), &(v[(v.size()-1) - k]));
			}
			break;
		}
	}
}

int main() {
	vector<int> v({5,5,4,3,23,6,9,8});
	print_vector(v);

	for (int i = 0; i < 5; i++) {
		next_larger_permutation(v);
		print_vector(v);
	}
}