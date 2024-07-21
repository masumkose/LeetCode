#include "../include/include.hpp"

class Solution
{
public:
	int trap(vector<int> &height)
	{
		int left = 0, right = height.size() - 1;
		int left_max = 0, right_max = 0;
		int water = 0;

		while (left < right)
		{
			if (height[left] <= height[right])
			{
				if (height[left] >= left_max)
					left_max = height[left];
				else
					water += left_max - height[left];
				left++;
			}
			else
			{
				if (height[right] >= right_max)
					right_max = height[right];
				else
					water += right_max - height[right];
				right--;
			}
		}
		return (water);
	}
};


// r_m = 0 / 1 / 2
// l_m = 0 / 1 / 2

// r = 1 / 2 / 1 / 2 / 3
// l = 0 / 1 / 1 / 2 / 1 / 0 / 1 / 3

// w = 0 + 1 + 1 + 2 + 1 + 1 = 6

int main()
{
	vector<vector<int>> heights;
	heights.push_back({0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1});
	heights.push_back({0, 1, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1});
	heights.push_back({4, 2, 0, 3, 2, 5});

	Solution ss;


	for (auto num : heights)
	{
		int res = ss.trap(num);
		cout << res << " = ";
		print_container(num);
	}


	return (0);
}