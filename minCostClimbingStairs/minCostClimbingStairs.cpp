

#include "../include/include.hpp"

class Solution
{
public:
	int minCostClimbingStairs(vector<int> &cost)
	{
		int size = cost.size();

		if (size == 2)
			return (min(cost[0], cost[1]));
		for (int i = 2; i < size; i++)
		{
			cost[i] += cost[i - 1] < cost[i - 2] ? cost[i - 1] : cost[i - 2];
		}

		return (cost[size - 1] < cost[size - 2] ? cost[size - 1] : cost[size - 2]);
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> costs = {
		{10, 15, 20},
		{1, 100, 1, 1, 1, 100, 1, 1, 100, 1}};

	for (auto cost : costs)
	{
		cout << ss.minCostClimbingStairs(cost) << '\n';
	}

	return (0);
}
