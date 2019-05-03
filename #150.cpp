#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

vector<vector<int>> k_nearest_neighbors(vector<vector<int>>& points, pair<int, int> center, int k) {
	// Compute distances and make pair with the correponding index
	vector<pair<int, int>> distances;
	for (int i = 0; i < points.size(); i++) {
		int dist = pow(points[i][0] - center.first, 2) + pow(points[i][1] - center.second, 2);
		distances.push_back(make_pair(dist, i));
	}

	// Sort the points based on their distance to the center
	sort(distances.begin(), distances.end(), [](pair<int, int> a, pair<int, int> b) {
		return a.first < b.first;
	});

	// Get k nearest neighbors using smallest distances and corresponding index
	vector<vector<int>> nearest_neighbors;
	for (int i = 0; i < k; i++) {
		nearest_neighbors.push_back(points[distances[i].second]);
	}

	return nearest_neighbors;
}

int main() {
	vector<vector<int>> points{{-1,-1}, {-2,-1}, {-3,-2}, {1,1}, {2,1}, {3,2}};
	pair<int, int> center = make_pair(1,2);
	vector<vector<int>> result = k_nearest_neighbors(points, center, 2);

	cout << "Nearest Neighbors: ";
	for (vector<int> point : result) {
		cout << "(" << point[0] << "," << point[1] << "), ";
	}
	cout << endl;
}