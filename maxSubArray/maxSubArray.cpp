
// divide and conquer algorithm in cpp



#include "../include/include.hpp"

class Solution
{
private:
	int maxCrossingSum(vector<int> &nums, int left, int mid, int right)
	{
		int leftsum = INT_MIN;
		int rightsum = INT_MIN;
		int sum = 0;

		for (int i = mid; i >= left; i--)
		{
			sum += nums[i];
			if (sum > leftsum)
				leftsum = sum;
		}

		sum = 0;

		for (int i = mid + 1; i <= right; i++)
		{
			sum += nums[i];
			if (sum > rightsum)
				rightsum = sum;
		}

		return (leftsum + rightsum);
	}


	int maxSubArraySum(vector<int> &nums, int left, int right)
	{
		if (left == right)
			return (nums[left]);

		int mid = left + (right - left) / 2;

		int leftMax = maxSubArraySum(nums, left, mid);
		int rightMax = maxSubArraySum(nums, mid + 1, right);
		int crossMax = maxCrossingSum(nums, left, mid, right);

		return (max({leftMax, rightMax, crossMax}));
	}


public:
	int maxSubArray(vector<int> &nums)
	{
		return (maxSubArraySum(nums, 0, nums.size() - 1));
	}
};

int main()
{
	Solution ss;

	vector<vector<int>> nums =
	{
		{-2,1,-3,4,-1,2,1,-5,4},
		{1},
		{5,4,-1,7,8}
	};

	for (auto num : nums)
	{
		cout << "Maximum subarray sum is = " << ss.maxSubArray(num) << '\n';
	}

	return (0);
}
