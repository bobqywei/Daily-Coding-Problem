#include<iostream>
#include<deque>
#include<cstdlib>
#include<vector>

using namespace std;

// Find area of largest consecutive block in histogram array
int largest_area_in_array(vector<int>& arr) {
	deque<int> stack;
	int max_area = 0;

	int i = 0;
	while (i < arr.size()) {
		if (stack.size() == 0 || arr[i] >= arr[stack.back()]) {
			stack.push_back(i++);
		} else {
			int top_val = arr[stack.back()];
			stack.pop_back();

			int area = top_val * (stack.size() == 0 ? i : i - stack.back() - 1);
			max_area = max(max_area, area);
		}
	}

	while (stack.size() > 0) {
		int top_val = arr[stack.back()];
		stack.pop_back();

		// here, i == arr.size()
		int area = top_val * (stack.size() == 0 ? i : i - stack.back() - 1);
		max_area = max(max_area, area);
	}

	return max_area;
}

int area_of_largest_rect(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<int> row(cols, 0);

	int max_rect = 0;
	for (int r = 0; r < rows; r++) {
		for (int c = 0; c < cols; c++) {
			if (matrix[r][c] == 1)
				row[c]++;
			else
				row[c] = 0;
		}
		int area = largest_area_in_array(row);
		max_rect = max(max_rect, area);
	}

	return max_rect;
}

int main() {
	vector<vector<int>> matrix({
		{1,0,0,0},
		{1,0,1,1},
		{1,0,1,1},
		{0,1,0,0}
	});

	int arr[] = {0,2,3,2,1,1,1,1};

	// cout << "Largest rectangle area: " << largest_area_in_array(arr, sizeof(arr)/sizeof(arr[0])) << endl;
	cout << "Largest rectangle area: " << area_of_largest_rect(matrix) << endl;
}