
#include "../include/include.cpp"

bool compareByLeftDigitOrder(int a, int b) {
    std::string sa = std::to_string(a);
    std::string sb = std::to_string(b);


    return sa + sb > sb + sa;
}



class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string str;

        sort(nums.begin(), nums.end(), compareByLeftDigitOrder);
        for (auto num : nums) {
            str = str + to_string(num);
        }
        if (str[0] == '0')
            return "0";
        return str;
    }
};



int main() {


    Solution ss = Solution();

    vector<vector<int>> numss =
    {
        {22, 2, 23},
    };


    for (auto nums : numss)
    {
        cout << ss.largestNumber(nums) << '\n';
    }


    return 0;
}
