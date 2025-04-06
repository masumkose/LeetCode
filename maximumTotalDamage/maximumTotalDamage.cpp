#include "../include/include.hpp"

/* 
A magician has various spells.

You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.

It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.

Each spell can be cast only once.

Return the maximum possible total damage that a magician can cast.

 

Example 1:

Input: power = [1,1,3,4]

Output: 6

Explanation:

The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.

Example 2:

Input: power = [7,1,6,6]

Output: 13

Explanation:

The maximum possible damage of 13 is produced by casting spells 1, 2, 3 with damage 1, 6, 6.

 */

class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        long long maxDamage = 0;
        set<int> visited;
        sort(power.begin(), power.end());
        reverse(power.begin(), power.end());
        backtrack(maxDamage, power, visited, 0, 0);
        return maxDamage;
    }



    void backtrack(long long &maxDamage, vector<int> &power, set<int> &visited, long long currentDamage, int index) {
        if (power.size() <= index) {
            maxDamage = max(maxDamage, currentDamage);
            return;
        }

        for (int i = index; i < power.size(); i++) {
            if (visited.find(power[i]) == visited.end()) {
                set<int> tempRestricted = visited;


                tempRestricted.insert(power[i]);
                tempRestricted.insert(power[i] - 2);
                tempRestricted.insert(power[i] - 1);
                tempRestricted.insert(power[i] + 1);
                tempRestricted.insert(power[i] + 2);
 
                backtrack(maxDamage, power, tempRestricted, currentDamage + power[i], i + 1);
            }
        }
        maxDamage = max(maxDamage, currentDamage);
    }
};


int main() {
    
    Solution ss = Solution();

    vector<vector<int>> nums = {
        {1,1,3,4},
        {7,1,6,6},
        {5,9,2,10,2,7,10,9,3,8},
    };


    for (auto &num : nums) {
        cout << ss.maximumTotalDamage(num) << endl;
    }
        
    return 0;
}
