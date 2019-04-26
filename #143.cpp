#include<iostream>
#include<vector>

using namespace std;

void print_vector(vector<int>& v) {
	for (int i : v) {
		cout << i << " ";
	}
	cout << endl;
}

bool LT(int a, int b) {
	return a < b;
}

bool EQ(int a, int b) {
	return a == b;
}

// Moves all elements that satisfy comparison to front of vector (defined by start)
template<typename Function>
int move_to_front(vector<int>& v, int start, int pivot, Function comparison) {
	int end = start;
	for (int i = start; i < v.size(); i++) {
		// Update "end" if element satisfies comparison
		if (comparison(v[i], pivot)) {
			// swap element to front if necessary
			if (i != end) {
				int temp = v[end];
				v[end] = v[i];
				v[i] = temp;
			}
			end++;
		}
	}
	// return the "end" index for elements that satisfy comparison
	return end;
}

void partition_array(vector<int>& v, int pivot) {
	// Move all elements less than pivot to start of vector
	int end_of_LT = move_to_front(v, 0, pivot, LT);
	// Move all elements equal to pivot to space immediately following the elements less than
	move_to_front(v, end_of_LT, pivot, EQ);
}

int main() {
	vector<int> test{9,12,3,5,14,10,10};
	print_vector(test);
	partition_array(test, 10);
	print_vector(test);
}
