
#include "../include/include.cpp"


class Solution {
public:
    long long smallestNumber(long long num) {
        if (num == 0) return 0;
        vector<int> digits;
        bool isNegative = (num < 0);

        long long n = abs(num);
        while (n > 0) {
            digits.push_back(n % 10);
            n = n / 10;
        }

        if (isNegative) {
            sort(digits.rbegin(), digits.rend());
        }
        else {
            sort(digits.begin(), digits.end());
        }

        if (digits[0] == 0) {
            for (size_t i = 1; i < digits.size(); i++) {
                if (digits[i] != 0) {
                    swap(digits[0], digits[i]);
                    break;
                }
            }
        }
        long long res = 0;

        for (auto &digit : digits) {
            res = res * 10 + digit;
        }
        
        return isNegative ? -res : res;
    }
};



int main() {


    Solution ss = Solution();

    vector<int> nums = {
        310,
        -7650,
    };


    for (auto num : nums) {
        cout << ss.smallestNumber(num) << endl;
    }

    return 0;
}
