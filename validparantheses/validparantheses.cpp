
#include "../include/include.cpp"


class Solution {
    public:
        bool isValid(string s) {
            stack<char> par;


            for (auto &ch : s) {
                if (ch == '(' || ch == '[' || ch == '{') {
                    par.push(ch);
                }
                else {
                    if (par.empty())
                        return false;
                    char ch2 = par.top();
                    par.pop();
                    if (ch == ')' && ch2 == '(')
                        continue;
                    else if (ch == '}' && ch2 == '{')
                        continue;
                    else if (ch == ']' && ch2 == '[')
                        continue;
                    else
                        return false;
                }
            }


            return par.empty() ? true : false;
    }
};



int main() {


    Solution ss = Solution();


    vector<string> strs = {
        "()",
        "()[]{}",
        "(]",
        "([])",
    };

    for (auto &s : strs) {
        cout << ss.isValid(s) << endl;
    }



    return 0;
}
