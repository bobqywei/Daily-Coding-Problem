#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>

using namespace std;

int max_profit_for_k(int k_buy_sells, vector<int>& stock_prices) {
	int profits[k_buy_sells + 1][stock_prices.size() + 1];
	
	// 0 profit on day 1
	for (int i = 0; i <= k_buy_sells; i++) {
		profits[i][0] = 0;
	}

	// 0 profit for 0 transactions
	for (int i = 0; i <= stock_prices.size(); i++) {
		profits[0][i] = 0;
	}

	for (int i = 1; i <= k_buy_sells; i++) {
		int best_net_buy = INT_MIN;

		for (int j = 1; j <= stock_prices.size(); j++) {

			// maximum possible profit if no sell at current price
			// same as max profit from previous day
			int no_sell = profits[i][j-1];

			// update best net profit over any previous buy price
			// (with limit of k-1 buy and sells)
			best_net_buy = max(best_net_buy, profits[i-1][j-1] - stock_prices[j-1]);

			// update the current day best profit for k buy and sells
			profits[i][j] = max(no_sell, best_net_buy + stock_prices[j]);
		}
	}

	return profits[k_buy_sells][stock_prices.size()];
}

int main() {
	int k = 2;
	vector<int> v({5,2,4,0,1});
	int max_profit = max_profit_for_k(k, v);
	cout << "Max profit is " << max_profit << endl;
}
