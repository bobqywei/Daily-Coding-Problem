#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int minCostPaintHouses(vector<vector<int>> costs) {
	int n = costs.size();
	int k = costs[0].size();
	int *minCost = new int[k];

	int min = 0;
	int min2 = 0;

	for (int i = 0; i < n; i++) {
		int prevMin = min;
		int prevMin2 = min2;

		min = INT_MAX;
		min2 = INT_MAX;

		for (int j = 0; j < k; j++) {
			minCost[j] = costs[i][j] + ((minCost[j] != prevMin) ? prevMin : prevMin2);

			if (minCost[j] < min) {
				min2 = min;
				min = minCost[j];
			} else {
				min2 = std::min(min2, minCost[j]);
			}
		}
	}

	return min;
}

int main() {
	vector<vector<int>> costs = {{5,1,2},{6,7,3},{5,2,3},{4,1,3}};
	cout << "Minimum Cost:" << minCostPaintHouses(costs) << endl;
}
