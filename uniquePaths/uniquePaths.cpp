

#include "../include/include.hpp"

// bactracking comes too slow for the solution of this promblem...
/*class Solution
{
public:
	void backtrac(int row, int col, int m, int n, long &paths)
	{
		if (row >= m || col >= n)
			return ;
		if (row == m - 1 && col == n - 1)
			paths++;

		backtrac(row + 1, col, m, n, paths);
		backtrac(row, col + 1, m, n, paths);
	}


	int uniquePaths(int m, int n)
	{
		long pat = 0;

		backtrac(0, 0, m, n, pat);

		return (pat);
	}
};*/

class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		vector<vector<int>> dp(m, vector<int>(n, 1));
		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
		return (dp[m - 1][n - 1]);
	}
};

int main()
{
	Solution ss;

	cout << ss.uniquePaths(3, 7) << '\n';
	cout << ss.uniquePaths(3, 2) << '\n';
	cout << ss.uniquePaths(19, 13) << '\n';
	cout << ss.uniquePaths(23, 12) << '\n';
	return (0);
}
