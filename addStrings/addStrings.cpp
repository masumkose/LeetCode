
#include "../include/include.cpp"

class Solution {
public:
    string addStrings(string num1, string num2) {

        int len1 = num1.length() - 1;
        int len2 = num2.length() - 1;
        string res;
        int ex = 0;

        while (len1 >= 0 || len2 >= 0)
        {
            char ch;
            if (len1 >= 0 && len2 >= 0)
            {
                char ch1 = num1[len1];
                char ch2 = num2[len2];
                ch = ch1 + ch2 - ('0') + ex;;
                if (ch > '9')
                {
                    ex = 1;
                    ch = ch - 10;
                }
                else 
                    ex = 0;
                res.insert(0,1,ch);
            }
            else if (len1 >= 0)
            {
                ch = num1[len1] + ex;
                if (ch > '9')
                {
                    ex = 1;
                    ch = ch - 10;
                }
                else 
                    ex = 0;
                res.insert(0,1,ch);
            }
            else if (len2 >= 0)
            {
                ch = num2[len2] + ex;
                if (ch > '9')
                {
                    ex = 1;
                    ch = ch - 10;
                }
                else 
                    ex = 0;
                res.insert(0,1,ch);
            }
            len1--;
            len2--;
        }
        if (ex)
            res.insert(0,1,'1');
        return res;
    }
};


int main() {


    Solution ss = Solution();


    vector<pair<string, string>> nums = {
        {"19", "123"},
        {"456", "77"},
        {"0", "0"}
    };

    for (auto num : nums)
    {
        cout << ss.addStrings(num.first, num.second) << endl;
    }


    return 0;
}
