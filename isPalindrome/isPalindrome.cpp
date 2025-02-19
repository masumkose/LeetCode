
#include "../include/include.cpp"

class Solution {
public:
    bool isPalindrome(string s) {

        string str = characterizeString(s);
        int len = str.size();
        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - i - 1])
                return false;
        }

        return true;
    }


    string characterizeString(string s)
    {
        string n;
        for (int i = 0; s[i]; i++)
        {
            if (s[i] >= 97 && s[i] <= 122)
                n.push_back(s[i]);
            else if (s[i] >= 65 && s[i] <= 90)
                n.push_back(s[i] + 32);
            else if (s[i] >= '0' && s[i] <= '9')
                n.push_back(s[i]);
        }
        return n;
    }
};


int main() {


    Solution ss = Solution();

    vector<string> in = {
        "A man, a plan, a canal: Panama",
        "race a car",
        " "
    };

    for (auto i : in)
    {
        cout << ss.isPalindrome(i) << '\n';
    }


    return 0;
}
