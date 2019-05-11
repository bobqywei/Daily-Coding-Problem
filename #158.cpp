#include<iostream>
#include<vector>

using namespace std;

int recursive_search(int curr_row, int curr_col, vector<vector<int>>& matrix, vector<vector<int>>& memo) {
	int rows = matrix.size();
	int cols = matrix[0].size();

	if (memo[curr_row][curr_col] == -1) {
		int ways = 0;
		if (curr_row < rows - 1) ways += recursive_search(curr_row + 1, curr_col, matrix, memo);
		if (curr_col < cols - 1) ways += recursive_search(curr_row, curr_col + 1, matrix, memo);
		memo[curr_row][curr_col] = ways;
	}

	return memo[curr_row][curr_col];
}

int num_ways(vector<vector<int>>& matrix) {
	int rows = matrix.size();
	int cols = matrix[0].size();
	
	vector<vector<int>> memo(rows, vector<int>(cols, -1));
	// at the finish, there is only 1 way
	memo[rows-1][cols-1] = 1;
	// at wall positions, there are 0 ways
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			if (matrix[i][j] == 1)
				memo[i][j] = 0;
		}
	}

	return recursive_search(0, 0, matrix, memo);
}

int main() {
	vector<vector<int>> matrix = {
		{0,0,1},
		{0,0,1},
		{1,0,0}
	};
	cout << num_ways(matrix) << endl;
}