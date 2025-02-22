
#include "../include/include.cpp"


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        set<vector<int>> visited;
        sort(nums.begin(), nums.end());
        backtrack(0, res, curr, nums, nums.size(), visited);
        return res;
    }





    void backtrack(int start, vector<vector<int>> &res, vector<int> &curr, vector<int> &nums, int size, set<vector<int>> &visited) {
        if (start > size)
        {
            return;
        }

        if (visited.find(curr) == visited.end())
        {
            visited.insert(curr);
            res.push_back(curr);
        }

        for (int i = start; i < size; i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, res, curr, nums, size, visited);
            curr.pop_back();
        }

    }
};



int main() {


    Solution ss = Solution();


    vector<vector<int>> nums = {
        {2,2,1},
        {0},
    };


    for (auto &num : nums) {
        print_nested_container(ss.subsetsWithDup(num));
    }


    return 0;
}
