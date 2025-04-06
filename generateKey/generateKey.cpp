
#include "../include/include.cpp"



class Solution {
public:
    int generateKey(int num1, int num2, int num3) {

        vector<int> digits;
        while (num1 > 0 || num2 > 0 || num3 > 0) {
            int smallestNumber = 0;
            if (num1 == 0 || num2 == 0 || num3 == 0) {
                smallestNumber = 0;
            }
            else if (num1 % 10 <= num2 % 10 && num1 % 10 <= num3 % 10) {
                smallestNumber = num1 % 10;
            }
            else if (num2 % 10 <= num1 % 10 && num2 % 10 <= num3 % 10) {
                smallestNumber = num2 % 10;
            }
            else {
                smallestNumber = num3 % 10;
            }

            num1 /= 10;
            num2 /= 10;
            num3 /= 10;
            digits.insert(digits.begin(), smallestNumber);
            // digits.push_back(smallestNumber);
        }
        int res = 0;
        for (auto &digit : digits) {
            res = res * 10 + digit;
        }
        return res;
    }
};


int main() {


    Solution ss = Solution();

    cout << ss.generateKey(1,2,3) << endl;


    return 0;
}
