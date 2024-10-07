

#include "../include/include.hpp"

/* Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.



Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true */

/* 219.
Contains Duplicate II
Easy
Topics
Companies
Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.



Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3:

Input: nums = [1,2,3,1,2,3], k = 2
Output: false
*/

class Solution
{
public:
	bool containsDuplicate(vector<int> &nums)
	{
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size() - 1; i++)
		{
			if (nums[i] == nums[i + 1])
				return true;
		}
		return false;
	}

	bool containsNearbyDuplicate(vector<int> &nums, int k) // solved with hash table!
	{
		map<int, int> mymap;
		int size = nums.size();
		for (int i = 0; i < size; i++)
		{
			if (mymap.find(nums[i]) == mymap.end())
				mymap[nums[i]] = i;
			else
			{
				if (abs(mymap[nums[i]] - i) <= k)
					return true;
				else
					mymap[nums[i]] = i;
			}
		}
		return false;
	}

	bool containsNearbyAlmostDuplicate(vector<int> &nums, int indexDiff, int valueDiff)
	{

	}
};

int main()
{
	Solution ss;
	vector<int> nums = {1,2,3,1};
	// cout << ss.containsDuplicate(nums) << '\n';
	//cout << ss.containsNearbyDuplicate(nums, 2) << '\n';
	cout << ss.containsNearbyAlmostDuplicate(nums, 3, 0);

	return (0);
}
