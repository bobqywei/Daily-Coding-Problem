#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minCostPaintHouses(vector<vector<int>> costs) {
	int n = costs.size();
	int k = costs[0].size();
	int *minCost = new int[k];

	// Only need to track ongoing lowest and second lowest costs
	int min = 0;
	int min2 = 0;

	for (int i = 0; i < n; i++) {
		int prevMin = min;
		int prevMin2 = min2;

		min = INT_MAX;
		min2 = INT_MAX;

		for (int j = 0; j < k; j++) {
			// Uses either the lowest or second lowest cost from previous house
			// based on if previous house's colour == j
			minCost[j] = costs[i][j] + ((minCost[j] != prevMin) ? prevMin : prevMin2);

			// Update the lowest and second lowest costs
			if (minCost[j] < min) {
				min2 = min;
				min = minCost[j];
			} else {
				min2 = std::min(min2, minCost[j]);
			}
		}
	}
	// Lowest painting cost for the last house is the return value
	return min;
}

int main() {
	vector<vector<int>> costs = {{5,1,2},{6,7,3},{5,2,3},{4,1,3}};
	cout << "Minimum Cost:" << minCostPaintHouses(costs) << endl;
}
