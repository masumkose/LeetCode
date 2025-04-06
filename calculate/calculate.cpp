#include "../include/include.hpp"


class Solution {
public:
    int calculate(string s) {
        stack<char> operator;
        stack<int> digits;
        int num = 0;


        for (auto ch : s) {
            if (isdigit(ch))
                digits.push(ch);
            else if (ch == '(')
                //
            else if (ch == ')')
                //
            else if (ch == '+' || ch == '-')
                operator.push(ch);
            else
                continue;
        }      
    }
};


int main() {
    
    Solution ss = Solution();

        
    return 0;
}
