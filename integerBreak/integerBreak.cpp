
#include "../include/include.hpp"

class Solution {
public:
    int integerBreak(int n) {

        vector<int> dp;

        dp.push_back(0); // 0
        dp.push_back(0);// 1
        dp.push_back(1);// 2
        dp.push_back(2);// 3
        dp.push_back(4);// 4
        dp.push_back(6);// 5
        dp.push_back(9);// 6
        dp.push_back(12);// 7


        for (int i = 8; i <= n + 1; i++)
        {
            dp.push_back(dp[i - 3] * 3);
        }
        return dp[n];
    }
};



int main()
{
    Solution ss = Solution();


    cout << ss.integerBreak(2) << '\n';

    cout << ss.integerBreak(10) << '\n';

    return 0;
}