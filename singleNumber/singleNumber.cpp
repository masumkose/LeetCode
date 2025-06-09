
#include "../include/include.cpp"



class Solution {
    public:
        int singleNumber(vector<int>& nums) {
            unordered_map<int, int> countMap;

            for (int num : nums){
                countMap[num]++;
            }

            for (auto &pair : countMap) {
                if (pair.second == 1){
                    return pair.first;
                }
            }

            return -1;
            
        }
        int singleNumber_I(vector<int>& nums) {
            unordered_set<int> nums_set;
            
            for (auto num : nums) {
                if (nums_set.find(num) == nums_set.end()) {
                    nums_set.insert(num);
                }
                else {
                    nums_set.erase(num);
                }
            }

            return *nums_set.begin();
        }
    };


int main() {


    Solution ss = Solution();

    vector<int> nums = {2,2,1};

    cout << ss.singleNumber(nums) << '\n';


    return 0;
}
