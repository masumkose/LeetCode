
#include "../include/include.cpp"

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> choose;
        backtrack(1,n,k,choose, res);
        return res;
    }


    void backtrack(int start, int n, int k, vector<int> &choose, vector<vector<int>> &res)
    {
        if (choose.size() == k)
        {
            res.push_back(choose);
            return;
        }
        for (int i = start; i <= n; i++)
        {
            choose.push_back(i);
            backtrack(i + 1, n,k,choose,res);
            choose.pop_back();
        }
    }
};


int main() {


    Solution ss = Solution();

    vector<pair<int, int>> nums = {
        {4,2},
        {1,1}
    };

    for (auto num : nums)
    {
        print_nested_container(ss.combine(num.first, num.second));
    }



    return 0;
}
