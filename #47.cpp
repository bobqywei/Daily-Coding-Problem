#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

int maxStockProfit(vector<int> &v) {
	if (v.size() == 0) return 0;

	int maxProfit = -1;
	int buyPrice = v[0];

	for (int i = 1; i < v.size(); i++) {
		if (v[i] < buyPrice) buyPrice = v[i];
		else maxProfit = max(maxProfit, v[i] - buyPrice);
	} 

	return max(maxProfit, 0);
}

int main() {
	vector<int> v = {9, 11, 8, 5, 7, 10};
	cout << "The maximum profit is " << maxStockProfit(v) << "." << endl;
}