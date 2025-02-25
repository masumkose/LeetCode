
#include "../include/include.cpp"



class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> res;
        set<int> memo;
        string current = expression;
        backtrack(0, 0, expression.size(), current, expression, memo, res); // start, total, str  res
        return res;
    }


    void backtrack(int start, int end, int total, int size, string &current, string expression, set<int> memo, vector<int> res) {
        if (start == size)
        {
            if (memo.find(total) == memo.end()) {
                res.push_back(total);
                memo.insert(total);
            }
            return;
        }


        for (int i = 0; i < size; i++) {
            int start = i;
            string sub_1;
            string sub_2;
            char op;
            while (i < current.length() && isdigit(current[i])) {
                sub_1.push_back(current[i]);
                i++;
            }
            if (i < current.length()) {
                op = current[i];
                i++;
            while (i < current.length() && isdigit(current[i])) {
                sub_2.push_back(current[i]);
                i++;
            }

    }
};


int main() {


    Solution ss = Solution();
    vector<string> nums = {
        "2-1-1",
        "2*3-4*5",
    };

    for (auto num : nums) {
        print_container(ss.diffWaysToCompute(nums));
    }



    return 0;
}
