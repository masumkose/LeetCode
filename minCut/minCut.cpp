
#include "../include/include.cpp"

class Solution {
public:
    int minCut(string s) {

        vector<vector<string>> res;
        vector<string> cuurentPart;
        generateSubstrings(s, 0, cuurentPart, res);
        int min = 2001;
        for (auto &r : res)
        {
            if (r.size() - 1 < min)
                min = r.size() - 1;
        }

        return min;
    }


    void generateSubstrings(string &s, int start, vector<string> &cuurentPart, vector<vector<string>> &res)
    {
        if (start == s.length())
        {
            res.push_back(cuurentPart);
            return;
        }


        for (int i = start; i < s.length(); i++)
        {
            string substring = s.substr(start, i - start + 1);
            if (isPalindrome(substring))
            {
                cuurentPart.push_back(substring);
                generateSubstrings(s, i + 1, cuurentPart, res);
                cuurentPart.pop_back();
            }
        }
    }


    bool isPalindrome(string &str) {
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
        cout << (ss.minCut(str)) << endl;
    }


    return 0;
}
