

#include "../include/include.hpp"

class Solution
{
public:
	vector<int> findErrorNums(vector<int> &nums)
	{
		vector<int> res;
		map<int, bool> myMap;
		int x, y;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++)
		{
			myMap[nums[i]] = true;
			if (i + 1 < nums.size() && nums[i] == nums[i + 1])
				x = nums[i];
			if (i + 1 != nums[i] && myMap[i + 1])
				y = i + 1;
		}
		res.push_back(x);
		res.push_back(y);
		return (res);
	}
};

int main()
{
	Solution ss;
	vector<vector<int>> nums = {{1,2,2,4}, {1,1}, {2,2}, {3,2,2}, {3,2,3,4,6,5}, {1,5,3,2,2,7,6,4,8,9}};
	for (auto num : nums)
		print_container(ss.findErrorNums(num));
	return (0);
}
