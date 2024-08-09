

#include "../include/include.hpp"

class Solution
{
public:
	int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
	{
		if (obstacleGrid[0][0] == 1)
			return (0);

		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));
		dp[0][0] = 1;

		for (int i = 1; i < m; i++)
		{
			dp[i][0] = obstacleGrid[i][0] == 1 ? 0 : dp[i - 1][0];
		}

		for (int j = 1; j < n; j++)
		{
			dp[0][j] = obstacleGrid[0][j] == 1 ? 0 : dp[0][j - 1];
		}

		for (int i = 1; i < m; i++)
		{
			for (int j = 1; j < n; j++)
			{
				if (obstacleGrid[i][j] == 1)
					dp[i][j] = 0;
				else
					dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}

		return (dp[m - 1][n - 1]);
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> obstacleGrid =
		{
			{0, 0, 0},
			{0, 1, 0},
			{0, 0, 0}};

	vector<vector<int>> obstacleGrid2 =
		{
			{0, 1},
			{0, 0}};

	cout << ss.uniquePathsWithObstacles(obstacleGrid) << '\n';
	cout << ss.uniquePathsWithObstacles(obstacleGrid2) << '\n';

	return (0);
}
