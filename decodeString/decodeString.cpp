
#include "../include/include.cpp"

class Solution {
public:
    string decodeString(string s) {
        string currentstr;
        stack<int> mult;
        stack<string> strvalues;
        int num = 0;

        for (auto ch : s) { //   "3[a]2[bc]",
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }
            else if (ch == '[') {
                mult.push(num);
                strvalues.push(currentstr);
                num = 0;
                currentstr = "";
            }
            else if (ch == ']') {
                int repeat = mult.top();
                mult.pop();
                
                string temp = strvalues.top();
                strvalues.pop();
                for (int i = 0; i < repeat; i++) {
                    temp += currentstr;
                }
                currentstr = temp;
            }
            else {
                currentstr += ch;
            }
        }
        return currentstr;
    }
};


int main() {


    Solution ss = Solution();

    vector<string> strs = {
        "3[a]2[bc]",
        "3[a2[a2[c]]]",
        "2[abc]3[cd]ef",
    };

    for (auto &str : strs) {
        cout << ss.decodeString(str) << endl;
    }


    return 0;
}
