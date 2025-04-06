
#include "../include/include.cpp"

class Solution {
public:
    vector<vector<string>> partition(string s) {

        vector<vector<string>> res;
        vector<string> cuurentPart;
        generateSubstrings(s, 0, cuurentPart, res);
        return res;
    }


    void generateSubstrings(string &s, int start, vector<string> &cuurentPart, vector<vector<string>> &res)
    {
        if (start == s.length())
        {
            res.push_back(cuurentPart);
            return;
        }


        for (int i = start; i < s.length(); i++)   // start = 0, i = 1 
        {
            string substring = s.substr(start, i - start + 1); // first aa   start = 1, i = 1
            if (isPalindrome(substring))
            {
                cuurentPart.push_back(substring); // have a in it  aa, 
                generateSubstrings(s, i + 1, cuurentPart, res);
                cuurentPart.pop_back();
            }
        }
    }


    bool isPalindrome(string str) {
        int len = str.size();

        for (int i = 0; i < len / 2; i++)
        {
            if (str[i] != str[len - i - 1])
                return false;
        }
        return true;
    }
};


int main() {


    Solution ss = Solution();

    vector<string> strings = {
        "baab"
    };

    for (auto str : strings)
    {
        print_nested_container(ss.partition(str));
    }


    return 0;
}
