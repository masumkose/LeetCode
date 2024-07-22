

#include "../include/include.hpp"

class Solution
{
public: // 5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5 i = 1 current end = 5 farthest = 7 jumps = 1
	int jump(vector<int> &nums)
	{
		if (nums.size() < 2) return 0;

		int jumps = 0;
		int currentend = 0;
		int farthest = 0;

		for(int i = 0; i < nums.size() - 1; i++)
		{
			farthest = max(farthest, i + nums[i]);
			if (i == currentend)
			{
				jumps++;
				currentend = farthest;
			}
		}

		return jumps;
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> nums;

	nums.push_back({2,3,1,1,4});

	nums.push_back({2,3,0,1,4});

	nums.push_back({5,6,4,4,6,9,4,4,7,4,4,8,2,6,8,1,5,9,6,5,2,7,9,7,9,6,9,4,1,6,8,8,4,4,2,0,3,8,5});


	for (auto num : nums)
	{
		cout << ss.jump(num) << endl;
	}

	return (0);
}
