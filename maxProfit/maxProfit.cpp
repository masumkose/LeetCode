

#include "../include/include.hpp"

class Solution
{
public:
	int maxProfit_I(vector<int> &prices)
	{
		int minPrice = INT_MAX;
		int maxProfit = 0;

		for (auto price : prices)
		{
			if (price < minPrice)
				minPrice = price;

			int profit = price - minPrice;
			if (maxProfit < profit)
				maxProfit = profit;
		}
		return maxProfit;
	}

	int maxProfit_II(vector<int> &prices)
	{
		int minPrice = INT_MAX;
		int maxProfit = 0;

		for (auto price : prices)
		{
			if (price < minPrice)
				minPrice = price;

			int profit = price - minPrice;
			if (profit > 0)
			{
				maxProfit += profit;
				minPrice = price;
			}
		}
		return maxProfit;
	}

	vector<vector<vector<int>>> memo;

	int dp_V1(vector<int> &prices, int i, int k, bool holding)
	{
		if (k == 0 || i >= prices.size())
			return 0;

		if (memo[holding][k][i] != -1)
			return memo[holding][k][i];

		int result = dp_V1(prices, i + 1, k, holding);

		if (holding)
		{
			result = max(result, dp_V1(prices, i + 1, k - 1, false) + prices[i]); // sell
		}
		else
		{
			result = max(result, dp_V1(prices, i + 1, k, true) - prices[i]); // buy
		}
		memo[holding][k][i] = result;
		return (memo[holding][k][i]);
	}

	int maxProfit_III_V1(vector<int> &prices)
	{
		memo.resize(2, vector<vector<int>>(3, vector<int>(prices.size(), -1)));
		return (dp_V1(prices, 0, 2, false));
	}

	int maxProfit(int k, vector<int> &prices)
	{
		memo.resize(2, vector<vector<int>>(k + 1, vector<int>(prices.size(), -1)));
		return (dp_V1(prices, 0, k, false));
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> prices = {{2,4,1}, {3,2,6,5,0,3}};

	for (auto price : prices)
	{
		cout << ss.maxProfit(2, price) << '\n';
	}

	return (0);
}
