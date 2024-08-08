

#include "../include/include.hpp"

class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums, int k)
	{
		vector<vector<int>> res;
		int i = 0;

		sort(nums.begin(), nums.end());
		int size = nums.size();

		do
		{
			res.push_back(nums);
			i++;
		} while (next_permutation(nums.begin(), nums.end()) && i < k);
		return (res);
	}

	string getPermutation(int n, int k)
	{
		vector<int> nums;
		string res;
		for (int i = 1; i <= n; i++)
		{
			nums.push_back(i);
		}
		vector<vector<int>> ans = permute(nums, k);
		for (int i = 0; i < n; i++)
		{
			res.push_back(ans[k - 1][i] + '0');
		}

		return (res);
	}
};

int main()
{
	Solution ss;

	cout << ss.getPermutation(8, 8590) << '\n';

	return (0);
}
