#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

int attackPairs(vector<pair<int, int>> &bishops) {
	int index = 0;
	int numPairs = 0;
	while (index < bishops.size() - 1) {
		for (int i = index+1; i < bishops.size(); i++) {
			if (abs(bishops[index].first - bishops[i].first) == 
				abs(bishops[index].second - bishops[i].second)) 
			{
				numPairs++;	
			}
		}
		index++;
	}
	return numPairs;
}

int main() {
	vector<pair<int, int>> bishops;
	string inp;
	cin >> inp;
	int n = stoi(inp);

	for (int i = 0; i < n; i++) {
		cin >> inp;
		int x = stoi(inp);
		cin >> inp;
		int y = stoi(inp);
		bishops.push_back(make_pair(x, y));
		cout << "Inserted pair (" << x << ", " << y << ")." << endl;
	}

	cout << endl << "Pairs of bishops that can attack each other: " 
		 << attackPairs(bishops) << endl;
}