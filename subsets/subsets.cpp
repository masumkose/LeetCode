
#include "../include/include.cpp"



class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        backtrack(0, nums.size(), subset, res, nums);
        return res;
    }




    void backtrack(int start, int size, vector<int> &subset, vector<vector<int>> &res, vector<int> &nums)
    {
        if (start > size)
            return;
        res.push_back(subset);

        for (int i = start; i < size; i++)
        {
            subset.push_back(nums[i]);
            backtrack(i + 1, size, subset, res, nums);
            subset.pop_back();
        }
    }
};



int main() {


    Solution ss = Solution();

    vector<vector<int>> nums = {
        {1,2,3},
        {0},
    };

    for (auto &num : nums)
    {
        print_nested_container(ss.subsets(num));
    }


    return 0;
}
