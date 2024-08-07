

#include "../include/include.hpp"

class Solution
{
public:
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int>> res;

		sort(nums.begin(), nums.end());
		int size = nums.size();

		do
		{
			res.push_back(nums);
		} while (std::next_permutation(nums.begin(), nums.end()));
		return (res);
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> nums = {
	{1, 2, 3},
	{0,-1,1},
	{1},
	{0, 1}
	};

	for (auto num : nums)
	{
		cout << "result for : ";
		print_container(num);
		print_nested_container(ss.permute(num));
		cout << ("-----------------\n");
	}

	return (0);
}
