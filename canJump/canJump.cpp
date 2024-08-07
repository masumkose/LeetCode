

#include "../include/include.hpp"

class Solution
{
public:
	bool canJump(vector<int> &nums)
	{
		if (nums.size() < 2)
			return (true);

		int target = nums.size() - 1;
		int currentend = 0;
		int farthest = 0;


		for(int i = 0; i < target; i++)
		{
			farthest = max(farthest, i + nums[i]);
			if (i == currentend)
			{
				currentend = farthest;
			}
			if (currentend >= target)
				return true;
		}
		return (false);
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> nums =
	{
		{2, 3, 1, 1, 4},
		{3, 2, 1, 0, 4},
		{},
		{1},
		{1, 2},
		{2, 0}
	};

	for (auto num : nums)
	{
		cout << "for nums = ";
		print_container(num);
		cout << (ss.canJump(num) ? "true" : "false") << endl;
	}

	return (0);
}