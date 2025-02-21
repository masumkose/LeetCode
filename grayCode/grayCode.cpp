
#include "../include/include.cpp"

#include <bitset>

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res = {0};
        unordered_set<int> visited = {0};



        backtrack(n,res, visited);
        return res;
    }



    bool backtrack(int n, vector<int> &res, unordered_set<int> &visited) {
        if (res.size() == (1 << n)) {
            return true;
        }

        int current = res.back();

        for (int i = 0; i < n; i++)
        {
            int next = current ^ (1 << i);

            if (visited.find(next) == visited.end()) {
                visited.insert(next);
                res.push_back(next);

                if (backtrack(n, res, visited))
                    return true;

                visited.erase(next);
                res.pop_back();
            }
        }
        return false;
    }
};



int main() {


    Solution ss = Solution();

    vector<int> nums = {
        2,1,3,15
    };


    for (auto &num : nums)
    {
        print_container(ss.grayCode(num));
    }


    return 0;
}
