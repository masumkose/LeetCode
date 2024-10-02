

#include "../include/include.hpp"

/*class Solution
{
public:
	int lenLongestFibSubseq(vector<int> &arr)
	{
		int n = arr.size();
		int res = 0;
		unordered_map<int, int> m;

		int dp[n][n];

		for (int j = 0; j < n; j++)
		{
			m[arr[j]] = j;
			for (int i = 0; i < j; i++)
			{
				int k = m.find(arr[j] - arr[i]) == m.end() ? -1 : m[arr[j] - arr[i]];

				dp[i][j] = (arr[j] - arr[i] < arr[i] && k >= 0) ? dp[k][i] + 1 : 2;
				res = max(res, dp[i][j]);
			}
		}

		return res > 2 ? res : 0;
	}
};*/

class Solution
{
public:
	int lenLongestFibSubseq(vector<int> &arr)
	{
		int n = arr.size();
		int res = 0;
		unordered_map <int, int> m;

		int dp[n][n];

		for (int j = 0; j < n; j++)
		{
			m[arr[j]] = j;
			for (int i = 0; i < j; i++)
			{
				int k = m.find(arr[j] - arr[i]) == m.end() ? -1 : m[arr[j] - arr[i]];
				dp[i][j] = (arr[j] - arr[i] < arr[i] && k >= 0) ? dp[k][i] + 1 : 2;
				res = max(res, dp[i][j]);
			}
		}
		return (res > 2 ? res : 0);
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> costs =
	{
		{1,2,3,4,5,6,7,8},
		{1,3,7,11,12,14,18}
	};

	for (auto cost : costs)
	{
		cout << ss.lenLongestFibSubseq(cost) << '\n';
	}

	return (0);
}
