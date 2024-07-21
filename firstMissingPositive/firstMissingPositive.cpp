#include "../../include.hpp"

class Solution
{
public:
	int firstMissingPositive(vector<int> &nums)
	{
		int i = 1;
		sort(nums.begin(), nums.end());
		vector<int>::iterator it;
		it = find(nums.begin(), nums.end(), 1);
		if ( it == nums.end() )
			return (1);
		for (; it != nums.end(); it++)
		{
			if (it != nums.begin() && *it == *(it - 1))
				continue;
			if (*it != i)
				return (i);
			i++;
		}
		return (i);
	}
};

void print_vector(const vector<int> &board)
{
	for (const auto num : board)
	{
		cout << num << ", ";
	}
	cout << '\n';
}

int main()
{
	vector<vector<int>> nums;
	nums.push_back({1,2,0});
	nums.push_back({3,4,-1,1});
	nums.push_back({7,8,9,11,12});
	nums.push_back({1});
	nums.push_back({1,1000});
	nums.push_back({0,2,2,1,1});


	Solution ss;
	for (auto num: nums)
	{
		int res = ss.firstMissingPositive(num);
		cout << res << " = ";
		print_vector(num);
	}

	return 0;
}