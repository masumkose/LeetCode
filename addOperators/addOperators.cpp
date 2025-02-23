
#include "../include/include.cpp"


// class Solution {
// public:
//     vector<string> addOperators(string num, int target) {
//         vector<string> res;
//         string sol;
//         backtrack(0, res, target, num, sol, num.length());
//         return res;
//     }


//     long long evaluateExpression(string s) {
//         stack<long long> stk; // Use long long
//         char sign = '+';
//         long long num = 0; // Use long long

//         for (int i = 0; i < s.length(); i++) {
//             if (isdigit(s[i])) {
//                 num = num * 10 + (s[i] - '0'); // Avoid int overflow
//             }

//             if (!isdigit(s[i]) && s[i] != ' ' || i == s.length() - 1) {
//                 if (sign == '+') {
//                     stk.push(num);
//                 } else if (sign == '-') {
//                     stk.push(-num);
//                 } else if (sign == '*') {
//                     long long top = stk.top(); stk.pop(); // Use long long
//                     stk.push(top * num);
//                 } else if (sign == '/') {
//                     long long top = stk.top(); stk.pop(); // Use long long
//                     stk.push(top / num);
//                 }

//                 sign = s[i];
//                 num = 0;
//             }
//         }

//         long long result = 0;
//         while (!stk.empty()) {
//             result += stk.top();
//             stk.pop();
//         }
//         return result;
//     }

//     void backtrack(int start, vector<string> &res, int target, string &num, string sol, int len) {
//         long long total = evaluateExpression(sol);
//         if (start == len) {
//             if (target == total)
//                 res.push_back(sol);
//             return;
//         }
//         for (int i = start; i < len; i++) {
//             if (i > start && num[start] == '0')
//                 break;
//             int sub_len = i - start + 1;
//             int original_size = sol.size();
//             string sub = num.substr(start, sub_len);
//             if (start == 0) {
//                 sol += sub;
//                 backtrack(i + 1, res, target, num, sol, len);
//                 sol.resize(original_size);
//             }
//             else {
//                 backtrack(i + 1, res, target, num, sol + "+" + sub, len);
//                 backtrack(i + 1, res, target, num, sol + "-" + sub, len);
//                 backtrack(i + 1, res, target, num, sol + "*" + sub, len);
//             }
//         }
//     }
// };

// class Solution {
// public:
//     vector<string> addOperators(string num, int target) {
//         vector<string> res;
//         string sol;
//         backtrack(0, 0, 0, res, target, num, sol, num.length());
//         return res;
//     }


//     void backtrack(int start, long long curr_value, long long last, vector<string> &res, int target, string &num, string sol, int len) {
//         if (start == len) {
//             if (target == curr_value)
//                 res.push_back(sol);
//             return;
//         }
//         for (int i = start; i < len; i++) {
//             if (i > start && num[start] == '0')
//                 break;
//             string sub = num.substr(start, i - start + 1);
//             long long sub_num = stoll(sub);
    
//             if (start == 0) {
//                 backtrack(i + 1, sub_num, sub_num, res, target, num, sol + sub, len);
//             }
//             else {
//                 backtrack(i + 1, curr_value + sub_num, sub_num, res, target, num, sol + "+" + sub, len);
//                 backtrack(i + 1, curr_value - sub_num, -sub_num, res, target, num, sol + "-" + sub, len);
//                 backtrack(i + 1, curr_value - last + last * sub_num, last * sub_num, res, target, num, sol + "*" + sub, len);
//             }
//         }
//     }
// };


class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        string str;
        backtrack(0,0,0, target, num.size(), str, num, res);  // pos, curr, last, target, len, str, num, res
        return res;
    }




    void backtrack(int pos, long long curr, long long last, int target, int size, string str, string &num, vector<string> &res) {
        if (pos == size) {
            if (curr == target) {
                res.push_back(str);
            }
            return;
        }

        for (int i = pos; i < size; i++) {
            if (i > pos && num[pos] == '0')
                break;

            string sub = num.substr(pos, i - pos + 1);
            long long sub_num = stoll(sub);

            if (pos == 0) {
                backtrack(i + 1, sub_num, sub_num, target, size, str + sub, num, res);
            }
            else {
                backtrack(i + 1, curr + sub_num, sub_num, target, size, str + "+" + sub, num, res);
                backtrack(i + 1, curr - sub_num, -sub_num, target, size, str + "-" + sub, num, res);
                backtrack(i + 1, curr - last + last * sub_num, last * sub_num, target, size, str + "*" + sub, num, res);
            }
        }


    }
};



int main() {


    Solution ss = Solution();

    vector<pair<string, int>> nums ={
        {"123", 6},
        {"232", 8},
        {"105", 5},
        {"3456237490", 9191},
    };


    for (auto &num : nums) {
        print_container(ss.addOperators(num.first, num.second));
    }



    return 0;
}
