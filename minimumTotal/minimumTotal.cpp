

#include "../include/include.hpp"

class Solution
{
public:
	map<pair<int,int>, int> memo;
	int dp(vector<vector<int>> &triangle, int i, int j)
	{
		if (i == triangle.size() - 1)
			return triangle[i][j];

		auto key = make_pair(i,j);
		if (memo.find(key) != memo.end())
			return memo[key];


		int right = triangle[i][j] + dp(triangle, i + 1, j + 1);
		int left = triangle[i][j] + dp(triangle, i + 1, j);
		return memo[key] = min({right, left});
	}


	int minimumTotal(vector<vector<int>> &triangle)
	{
		return dp(triangle, 0,0);
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
	vector<vector<int>> triangle2 = {{-10}};

	cout << ss.minimumTotal(triangle) << endl;
	cout << ss.minimumTotal(triangle2) << endl;


	return (0);
}
