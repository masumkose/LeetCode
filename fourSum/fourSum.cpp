
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
void print_vec(std::vector<int> nums);


template <typename T>
void printContainer(const T& container) {
    for (const auto& element : container) {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target)
	{

		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int n = nums.size();
		for (int i = 0; i < n - 3; i++)
		{
			if (i > 0 && nums[i] == nums[i - 1])
				continue;
			for (int j = i + 1; j < n - 2; j++)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
					continue;
				int left = j + 1;
				int right = n - 1;
				while (left < right)
				{
					long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
					if (sum == target)
					{
						result.push_back({nums[i], nums[j], nums[left], nums[right]});
						while (left < right && nums[left] == nums[left + 1])
							left++;
						while (left < right && nums[right] == nums[right - 1])
							right--;
						left++;
						right--;
					}
					else if (sum < target)
						left++;
					else
						right--;
				}
				
			}
		}
		return (result);
	}
};


int main()
{
	Solution x;
	vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
	vector<vector<int>> result = x.fourSum(nums, 0);


	for (auto res : result)
		printContainer(res);





	return (0);
}